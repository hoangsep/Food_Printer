
/*
  Arduino code for connecting the sensor to the computer
  Tran Minh Hoang A0088452X FYP

  capacitance value is in femto fara
  The checksum used is Fletcher's checksum
*/

// Global variables declaraton
uint16_t csum;
uint8_t c0,c1,f0,f1;
String data = "$";
int curPlate1 = 0;
int curPlate2 = 1;
uint16_t capacitance = 6000;

const int capacitanceInputPin = A6;
// The first plate
const int plate1A0Pin = 14;
const int plate1A1Pin = 15;
const int plate1A2Pin = 16;
// The second plate
const int plate2A0Pin = 17;
const int plate2A1Pin = 18;
const int plate2A2Pin = 19;
// The dischage valve
const int dischargeValveA0Pin = 20;
const int dischargeValveA1Pin = 21;
const int dischargeValveA2Pin = 22;
// Time for the capacitor to charge/discharge
const int chargeTime = 500;
// The const to convert from output voltage to measured capacitance
const float capacitanceConst = 1;
// The total number of plates
const int numberOfPlates = 4;

void setup() {
  // Initialize pinMode
  pinMode(capacitanceInputPin, INPUT);
  pinMode(plate1A0Pin, OUTPUT);
  pinMode(plate1A1Pin, OUTPUT);
  pinMode(plate1A2Pin, OUTPUT);
  pinMode(plate2A0Pin, OUTPUT);
  pinMode(plate2A1Pin, OUTPUT);
  pinMode(plate2A2Pin, OUTPUT);
  pinMode(dischargeValveA0Pin, OUTPUT);
  pinMode(dischargeValveA1Pin, OUTPUT);
  pinMode(dischargeValveA2Pin, OUTPUT);
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // prints title with ending line break 
  Serial.println("Start sending data"); 
} 

void loop() {
  // computation step
  capacitance = measureCapacitance(curPlate1, curPlate2);
  
  //output data step
  data = "$";
  // add the currently being measured plates
  data = data + "PL" + curPlate1 + curPlate2;
  // add the measured value
  data = data + "CA" + capacitance;
  // calculate the checksum
  csum = fletcher16(data);
  f0 = csum & 0xff;
  f1 = (csum >> 8) & 0xff;
  c0 = 0xff - (( f0 + f1) % 0xff);
  c1 = 0xff - (( f0 + c0 ) % 0xff);
  // add the checksum
  data = data + "*" + String(c0, HEX) + String(c1, HEX);
  // send the data
  Serial.println(data);
  
  if (!advancePlates())
    Serial.println("Error, cannot advance plates");

  delay(500);
} 

uint16_t measureCapacitance(uint8_t plate1, uint8_t plate2) {
  // Open the valve and wait
  digitalWrite(dischargeValveA0Pin, LOW);
  digitalWrite(dischargeValveA1Pin, LOW);
  digitalWrite(dischargeValveA2Pin, LOW);
  delay(chargeTime); // To be replaced with actual wait loop
  // Connect the first plate
  digitalWrite(plate1A0Pin, plate1 & B001);
  digitalWrite(plate1A1Pin, (plate1 >> 1) & B001);
  digitalWrite(plate1A2Pin, (plate1 >> 2) & B001);
  // Connect the second plate
  digitalWrite(plate2A0Pin, plate2 & B001);
  digitalWrite(plate2A1Pin, (plate2 >> 1) & B001);
  digitalWrite(plate2A2Pin, (plate2 >> 2) & B001);
  // Close the valve and wait
  digitalWrite(dischargeValveA0Pin, HIGH);
  digitalWrite(dischargeValveA1Pin, LOW);
  digitalWrite(dischargeValveA2Pin, LOW);
  delay(chargeTime); // To be replaced with actual wait loop
  // Read the analog input signal and convert
  int sensorValue = analogRead(capacitanceInputPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float capacitanceValue = voltage * capacitanceConst;
  // Output the date
  return (uint16_t)(capacitanceValue * 1000);
}

boolean advancePlates() {
  if (curPlate1 >= curPlate2 
    || curPlate1 >= numberOfPlates 
    || curPlate2 >= numberOfPlates) 
    return false;

  if (curPlate2 + 1 < numberOfPlates) curPlate2 += 1;
  else if (curPlate1 + 2 < numberOfPlates) {
    curPlate1 += 1;
    curPlate2 = curPlate1 + 1;
  }
  else {
    curPlate1 = 0;
    curPlate2 = 1;
  }

  return true;
}

uint16_t fletcher16( String data) {
	uint16_t sum1 = 0xff, sum2 = 0xff;
	uint8_t count = 0;
	size_t bytes = data.length();

	while (bytes) {
		size_t tlen = bytes > 20 ? 20 : bytes;
		bytes -= tlen;
		do {
			sum2 += sum1 += data[count++];
		} while (--tlen);
		sum1 = (sum1 & 0xff) + (sum1 >> 8);
		sum2 = (sum2 & 0xff) + (sum2 >> 8);
	}
        /* Second reduction step to reduce sums to 8 bits */
	sum1 = (sum1 & 0xff) + (sum1 >> 8);
	sum2 = (sum2 & 0xff) + (sum2 >> 8);
	return sum2 << 8 | sum1;
}

