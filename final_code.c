const int sensorPin = A0;
const int fanPin = 6;        // IRF540N Gate
const int greenPin = 9;      // Clean
const int yellowPin = 10;    // Moderate
const int redPin = 11;       // Polluted

const int moderate = 550;    // Your baseline
const int polluted = 650;    // Smoke threshold

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  digitalWrite(fanPin, LOW);
  Serial.begin(9600);
  Serial.println("LAPC Full System Ready!");
  delay(60000);  // Sensor warm-up
}

void loop() {
  int air = analogRead(sensorPin);
  Serial.print("Air: "); Serial.println(air);

  if (air > polluted) {
    // RED - Heavy pollution
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(fanPin, HIGH);  // Fans ON
    Serial.println(">>> RED: HEAVY SMOKE!");
  } else if (air > moderate) {
    // YELLOW - Moderate
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(fanPin, HIGH);  // Fans ON
    Serial.println(">> YELLOW: CLEANING...");
  } else {
    // GREEN - Clean
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(fanPin, LOW);   // Fans OFF
    Serial.println("> GREEN: CLEAN AIR!");
  }
  delay(1000);
}
