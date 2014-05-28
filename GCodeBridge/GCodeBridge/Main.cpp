#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// The ratio of each component in the totalFeed, sum of them = 1
double ratio1 = 0;
double ratio2 = 0;
double ratio3 = 0;

// Use the ratios to divide the feedrate to multiple extruders
string divideOutput(string);

int main() {
	ifstream origGCode("test.gcode");
	ofstream newGCode("fixedGCode.gcode");
	string line;
	double totalOutput = 0;

	// Ask for the ratio, will be replaced by the GUI
	cout << "Please input the ratio" << endl;
	cout << "extruder 1 ratio: " << endl;
	cin >> ratio1;
	cout << "extruder 2 ratio: " << endl;
	cin >> ratio2;
	cout << "extruder 3 ratio: " << endl;
	cin >> ratio3;
	totalOutput = ratio1 + ratio2 + ratio3;
	ratio1 = ratio1 / totalOutput;
	ratio2 = ratio2 / totalOutput;
	ratio3 = ratio3 / totalOutput;
	cout << "The extruders output ratio: " << ratio1 << " : " << ratio2 << " : " << ratio3 << endl;

	if (origGCode.is_open()) {
		if (newGCode.is_open()) {
			while (getline(origGCode, line)) {
				cout << line << endl;
				cout << " --- " << divideOutput(line) << " --- " << endl;
				newGCode << divideOutput(line) << endl;
			}
			newGCode.close();
		}
		else cout << "Unable to open output file!" << endl;
		origGCode.close();
	}
	else cout << "Unable to open input file!" << endl;
	system("pause");
	return 0;
}

// Use the ratios to divides the feedrate to multiple extruders
string divideOutput(string inputLine) {
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