#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Use the ratios to divide the feedrate to multiple extruders
string divideOutput(string);
int changeRatio(string, string, vector<int>, vector<int>);

int main() {
	string inFile = "in.gcode";
	string outFile = "out.gcode";
	string line;
	double totalOutput = 0;
	// The start ratio of each component in the totalFeed, sum of them = 1
	vector<int> starting_ratios (3, 0);
	// The end ratio of each component in the totalFeed, sum of them = 1
	vector<int> ending_ratios (3, 0);

	// Ask for the ratio, will be replaced by the GUI
	cout << "Please input the starting ratio in percent" << endl;
	cout << "Starting extruder 1 ratio: " << endl;
	cin >> starting_ratios[0];
	cout << "Starting extruder 2 ratio: " << endl;
	cin >> starting_ratios[1];
	cout << "Starting extruder 3 ratio: " << endl;
	cin >> starting_ratios[2];
	totalOutput = starting_ratios[0] + starting_ratios[1] + starting_ratios[2];
	
	if (totalOutput != 100) {
		starting_ratios[0] = (int)(starting_ratios[0] * 100 / totalOutput);
		starting_ratios[1] = (int)(starting_ratios[1] * 100 / totalOutput);
		starting_ratios[2] = (int)(starting_ratios[2] * 100 / totalOutput);
		if (starting_ratios[0] != 0) starting_ratios[0] = 100 - starting_ratios[1] - starting_ratios[2];
		else if (starting_ratios[1] != 0) starting_ratios[1] = 100 - starting_ratios[0] - starting_ratios[2];
		else if (starting_ratios[2] != 0) starting_ratios[2] = 100 - starting_ratios[0] - starting_ratios[1];
	}
	cout << "The extruders starting output ratio: " << starting_ratios[0] << " : " << starting_ratios[1] << " : " << starting_ratios[2] << endl;

	// Ask for the ratio, will be replaced by the GUI
	cout << "Please input the ending ratio in percent" << endl;
	cout << "Ending extruder 1 ratio: " << endl;
	cin >> ending_ratios[0];
	cout << "Ending extruder 2 ratio: " << endl;
	cin >> ending_ratios[1];
	cout << "Ending extruder 3 ratio: " << endl;
	cin >> ending_ratios[2];
	totalOutput = ending_ratios[0] + ending_ratios[1] + ending_ratios[2];
	
	
	if (totalOutput != 100) {
		ending_ratios[0] = (int)(ending_ratios[0] * 100 / totalOutput);
		ending_ratios[1] = (int)(ending_ratios[1] * 100 / totalOutput);
		ending_ratios[2] = (int)(ending_ratios[2] * 100 / totalOutput);
		if (ending_ratios[0] != 0) ending_ratios[0] = 100 - ending_ratios[1] - ending_ratios[2];
		else if (ending_ratios[1] != 0) ending_ratios[1] = 100 - ending_ratios[0] - ending_ratios[2];
		else if (ending_ratios[2] != 0) ending_ratios[2] = 100 - ending_ratios[0] - ending_ratios[1];
	}
	cout << "The extruders ending output ratio: " << ending_ratios[0] << " : " << ending_ratios[1] << " : " << ending_ratios[2] << endl;

	if (changeRatio(inFile, outFile, starting_ratios, ending_ratios)) {
		cout << "Successfully failed" << endl;
	}
	else {
		cout << "Conversion successful" << endl;
	}

	system("pause");
	return 0;
}

// Use the ratios to divides the feedrate to multiple extruders
string divideOutput(string inputLine, double ratio1, double ratio2, double ratio3) {
	// check if this is a move command
	if ((inputLine.substr(0, 2)).compare("G1") != 0) return inputLine;
	
	string result = inputLine;
	// find the E portion of the string
	unsigned int found = 0;
	found = inputLine.find('E');
	if (found != string::npos) {
		// find the new extrusion length of each extruder
		unsigned int nextSpace = inputLine.find(' ', found);
		if (nextSpace == string::npos) nextSpace = inputLine.size();
		double extrusionLength = stod(inputLine.substr(found+1, nextSpace - found - 1));
		double extruder1Length = extrusionLength * ratio1;
		double extruder2Length = extrusionLength * ratio2;
		double extruder3Length = extrusionLength * ratio3;
		// generate the new extrusion string
		ostringstream s;
		s << extruder1Length << ":" << extruder2Length << ":" << extruder3Length;
		// erase the old string
		result.erase(found + 1, nextSpace - found - 1);
		// insert the new string
		result.insert(found + 1, s.str());
	}

	return result;
}

// Gradually change the mixing ratio from start ratios to end ratios
int changeRatio(string inFile, string outFile, vector<int> starting_ratios, vector<int> ending_ratios) {
	// Debug printing
	cout << "---------------------------------------------------" << endl;
	cout << "changeRatio function is called" << endl;
	cout << "The starting ratios are: " << starting_ratios[0] << 
		":" << starting_ratios[1] << ":" << starting_ratios[2] << endl;
	cout << "The ending ratios are: " << ending_ratios[0] <<
		":" << ending_ratios[1] << ":" << ending_ratios[2] << endl;
	ifstream origGCode(inFile);
	ofstream newGCode(outFile);
	string line;
	unsigned int totalLines;
	unsigned int lineCount; // only count the movement line, like G1
	vector<int> current_ratios(3,0);
	vector<int> ratio_diffs(3,0);
	int totalOutput;
	int primaryRatio = 0;
	int secondRatio = 0;
	int thirdRatio = 0;
	double secondFinished = 0; // In percentage
	double thirdFinished = 0; // In percentage
	int updateInterval = 0; // in number of lines

	if (!origGCode.is_open()) {
		cout << "Unable to open input file!" << endl;
		origGCode.close();
		newGCode.close();
		return 1;
	}
	if (!newGCode.is_open()) {
		cout << "Unable to open output file!" << endl;
		origGCode.close();
		newGCode.close();
		return 1;
	}

	// Defensive programming, make sure all ratio sum up to 1
	totalOutput = starting_ratios[0] + starting_ratios[1] + starting_ratios[2];
	if (totalOutput != 100) {
		starting_ratios[0] = (int)(starting_ratios[0] * 100) / totalOutput;
		starting_ratios[1] = (int)(starting_ratios[1] * 100) / totalOutput;
		starting_ratios[2] = (int)(starting_ratios[2] * 100) / totalOutput;
		if (starting_ratios[0] + starting_ratios[1] + starting_ratios[2] != 100) {
			if (starting_ratios[0] != 0) starting_ratios[0] = 100 - starting_ratios[1] - starting_ratios[2];
			else if (starting_ratios[1] != 0) starting_ratios[1] = 100 - starting_ratios[0] - starting_ratios[2];
			else if (starting_ratios[2] != 0) starting_ratios[2] = 100 - starting_ratios[0] - starting_ratios[1];
		}
	}
	totalOutput = ending_ratios[0] + ending_ratios[1] + ending_ratios[2];
	if (totalOutput != 100) {
		ending_ratios[0] = (int)(ending_ratios[0] * 100) / totalOutput;
		ending_ratios[1] = (int)(ending_ratios[1] * 100) / totalOutput;
		ending_ratios[2] = (int)(ending_ratios[2] * 100) / totalOutput;
		if (ending_ratios[0] + ending_ratios[1] + ending_ratios[2] != 100) {
			if (ending_ratios[0] != 0) ending_ratios[0] = 100 - ending_ratios[1] - ending_ratios[2];
			else if (ending_ratios[1] != 0) ending_ratios[1] = 100 - ending_ratios[0] - ending_ratios[2];
			else if (ending_ratios[2] != 0) ending_ratios[2] = 100 - ending_ratios[0] - ending_ratios[1];
		}
	}
	// Initialize the current ratio variables
	current_ratios[0] = starting_ratios[0];
	current_ratios[1] = starting_ratios[1];
	current_ratios[2] = starting_ratios[2];
	// The ratio diff variables
	ratio_diffs[0] = ending_ratios[0] - starting_ratios[0];
	ratio_diffs[1] = ending_ratios[1] - starting_ratios[1];
	ratio_diffs[2] = ending_ratios[2] - starting_ratios[2];
	// Find the ratio with most change for Bresenham algorithm
	primaryRatio = 0;
	for (int i = 0; i < 3; i++) {
		if (abs(ratio_diffs[i]) > abs(ratio_diffs[primaryRatio]))
			primaryRatio = i;
	}

	totalLines = 0;
	while (getline(origGCode, line)) {
		if (line[0] == 'G') totalLines++;
	}
	updateInterval = totalLines / abs(ratio_diffs[primaryRatio]);
	// debug print
	cout << "Total number of movement lines: " << totalLines << endl;
	// Move the file pointer to the begining
	origGCode.clear();
	origGCode.seekg(0, origGCode.beg);

	lineCount = 0;
	secondRatio = (primaryRatio + 1) % 3; // So that secondaryRatio != primaryRatio
	thirdRatio = (primaryRatio + 2) % 3; // So we have primary ratio != secondRatio != thirdRatio
	// set the starting ratios
	newGCode << "M206 T3 P945" << " X" << current_ratios[0] << endl;
	newGCode << "M206 T3 P949" << " X" << current_ratios[1] << endl;
	newGCode << "M206 T3 P953" << " X" << current_ratios[2] << endl;
	while (getline(origGCode, line)) {
		if (line[0] == 'G') lineCount++;
		newGCode << line << endl;
		if (lineCount == updateInterval) {
			lineCount = 0;
			// Update the primary extruder ratio
			current_ratios[primaryRatio] += ratio_diffs[primaryRatio] / abs(ratio_diffs[primaryRatio]);
			newGCode << "M206 T3 P" << 945 + 4*primaryRatio << " X" << current_ratios[primaryRatio] << endl;
			// Compute the percent of change finished in second extruder
			if (ending_ratios[secondRatio] - starting_ratios[secondRatio] == 0)
				secondFinished = 1;
			else
				secondFinished = abs((current_ratios[secondRatio] - starting_ratios[secondRatio]) * 1.0 
					/ (ending_ratios[secondRatio] - starting_ratios[secondRatio]));
			// Compute the percent of change finished in third extruder
			if (ending_ratios[thirdRatio] - starting_ratios[thirdRatio] == 0)
				thirdFinished = 1;
			else
				thirdFinished = abs((current_ratios[thirdRatio] - starting_ratios[thirdRatio]) * 1.0
					/ (ending_ratios[thirdRatio] - starting_ratios[thirdRatio]));
			if (secondFinished <= thirdFinished) {
				// update the second ratio
				current_ratios[secondRatio] += ratio_diffs[secondRatio] / abs(ratio_diffs[secondRatio]);
				newGCode << "M206 T3 P" << 945 + 4 * secondRatio << " X" << current_ratios[secondRatio] << endl;
			}
			else {
				// update the third ratio
				current_ratios[thirdRatio] += ratio_diffs[thirdRatio] / abs(ratio_diffs[thirdRatio]);
				newGCode << "M206 T3 P" << 945 + 4 * thirdRatio << " X" << current_ratios[thirdRatio] << endl;
			}
		}
	}

	// Set the ending ratios
	newGCode << "M206 T3 P945" << " X" << current_ratios[0] << endl;
	newGCode << "M206 T3 P949" << " X" << current_ratios[1] << endl;
	newGCode << "M206 T3 P953" << " X" << current_ratios[2] << endl;

	cout << "---------------------------------------------------" << endl;
	origGCode.close();
	newGCode.close();
	return 0;
}