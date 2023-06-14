// Define the pins for delivering the stimuli
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;

// Define the frequency and duration of the stimuli
int frequency = 1000;
int duration = 800;

// Define the timing intervals between the stimuli
int interval1 = 1000;
int interval2 = 1000;
int interval3 = 1000;

// Define the pin for receiving input from the participant
int inputPin = 8;

// Define the variable for storing the participant's response
int response = 0;

void setup() {
  // Set the output pins for delivering the stimuli
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

  // Set the input pin for receiving the participant's response
  pinMode(inputPin, INPUT);

  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Deliver the first stimulus
  digitalWrite(pin1, HIGH);
  delay(duration);
  digitalWrite(pin1, LOW);
  Serial.println("Tap on contactor 1");

  // Wait for the first interval
  delay(interval1);

  // Deliver the second stimulus
  digitalWrite(pin2, HIGH);
  delay(duration);
  digitalWrite(pin2, LOW);
  Serial.println("Tap on contactor 2");

  // Wait for the second interval
  delay(interval2);

  // Deliver the third stimulus
  digitalWrite(pin3, HIGH);
  delay(duration);
  digitalWrite(pin3, LOW);
  Serial.println("Tap on contactor 3");

  delay(interval3);

//  // Deliver the fourth stimulus
//  digitalWrite(pin2, HIGH);
//  delay(duration);
//  digitalWrite(pin2, LOW);
//
//  // Wait for the fourth interval
//  delay(interval3);
//
//  // Deliver the fifth stimulus
//  digitalWrite(pin1, HIGH);
//  delay(duration);
//  digitalWrite(pin1, LOW);
//
//  // Wait for the fifth interval
//  delay(interval3);

  // Wait for the participant's response
  response = digitalRead(inputPin);

  // Send the participant's response to the serial monitor
  Serial.println(response);
}