#define STEPPIN 40
#define DIRPIN 42
#define ENPIN 65

void setup() {
  // set the digital pin as output:
  pinMode(STEPPIN, OUTPUT);
  pinMode(DIRPIN, OUTPUT);
  pinMode(ENPIN, OUTPUT);  
}

void loop()
{
    digitalWrite(STEPPIN, LOW);
    digitalWrite(DIRPIN, LOW);
    digitalWrite(ENPIN, LOW);
}

