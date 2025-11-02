How to Test the MQ-135 Air Quality Sensor (Step-by-Step)
While you (or adult) cut the fan jacks, test the MQ-135 sensor NOW — it takes 5 minutes and uses only your Arduino Uno, breadboard, and jumper wires.

Tools Needed

Arduino Uno (USB to laptop)
MQ-135 sensor
3x male-to-male jumper wires
Breadboard


Step 1: Wire the MQ-135 (30 Seconds)

MQ-135 PinConnect to Arduino
VCC          5V
GND          GND
AO           A0

MQ-135

  VCC ──→ Arduino 5V
  
  GND ──→ Arduino GN
  
  AO  ──→ Arduino A0

Step 2: Upload Test Code (1 Minute)
Open Arduino IDE → paste this:
cppvoid setup() {
  Serial.begin(9600);  // Open Serial Monitor
}

void loop() {
  int value = analogRead(A0);  // Read sensor
  Serial.print("MQ-135 Raw Value: ");
  Serial.println(value);
  delay(1000);  // Print every second
}
Upload → Open Serial Monitor (Ctrl+Shift+M) → set 9600 baud

Step 3: See Results (2 Minutes)

Air ConditionExpected ValueTest MethodClean room air80 – 200Just breathe normallyYour breath300 – 600Breathe directly on sensorSmoke / Dust600 – 1024Wave match smoke or dusty cloth
Sensor needs 2–5 min warm-up → values stabilize after that.
