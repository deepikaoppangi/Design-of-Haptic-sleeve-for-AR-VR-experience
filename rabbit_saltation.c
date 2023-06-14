const int pin1 = 2; // first contactor pin (near wrist)
const int pin2 = 3; // second contactor pin (middle of forearm)
const int pin3 = 4; // third contactor pin (near elbow)
const int numTaps1 = 5; // number of taps for first sequence
const int numTaps2 = 5; // number of taps for second sequence
const int tapInterval = 500; // interval between taps in ms, for rapid succession
const int pauseInterval = 1000; // interval between sequences in ms

void setup() {
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
Serial.begin(9600);
while (!Serial);
Serial.println("You are good to go.");
}

void loop() {
// sequence 1 - first contactor (near wrist)
for (int i = 0; i < numTaps1; i++) {
digitalWrite(pin1, HIGH);
Serial.println("Tap on contactor 1");
delay(tapInterval);
digitalWrite(pin1, LOW);
delay(tapInterval);
}
delay(pauseInterval);

// sequence 2 - second contactor (middle of forearm)
for (int i = 0; i < numTaps2; i++) {
digitalWrite(pin2, HIGH);
Serial.println("Tap on contactor 2");
delay(tapInterval);
digitalWrite(pin2, LOW);
delay(tapInterval);
}
delay(pauseInterval);

// sequence 3 - third contactor (near elbow)
for (int i = 0; i < numTaps1; i++) {
digitalWrite(pin3, HIGH);
Serial.println("Tap on contactor 3");
delay(tapInterval);
digitalWrite(pin3, LOW);
delay(tapInterval);
}
delay(pauseInterval);

// additional sequences - simulate the cutaneous rabbit illusion
// sequence 4 - taps hopping up the arm
digitalWrite(pin1, HIGH);
digitalWrite(pin2, HIGH);
Serial.println("Tap on contactor 1 and 2");
delay(tapInterval);
digitalWrite(pin1, LOW);
delay(tapInterval);
digitalWrite(pin2, LOW);
delay(tapInterval);

digitalWrite(pin2, HIGH);
digitalWrite(pin3, HIGH);
Serial.println("Tap on contactor 2 and 3");
delay(tapInterval);
digitalWrite(pin2, LOW);
delay(tapInterval);
digitalWrite(pin3, LOW);
delay(pauseInterval);

// sequence 6 - taps hopping down the arm
digitalWrite(pin3, HIGH);
digitalWrite(pin2, HIGH);
Serial.println("Tap on contactor 3 and 2");
delay(tapInterval);
digitalWrite(pin3, LOW);
delay(tapInterval);
digitalWrite(pin2, LOW);
delay(tapInterval);

digitalWrite(pin2, HIGH);
digitalWrite(pin1, HIGH);
Serial.println("Tap on contactor 2 and 1");
delay(tapInterval);
digitalWrite(pin2, LOW);
delay(tapInterval);
digitalWrite(pin1, LOW);
delay(pauseInterval);
//delay(pauseInterval-tapInterval);

}