const int contact1 = 2;
const int contact2 = 3;
const int contact3 = 4;
const int threshold = 500;

void setup() {
  pinMode(contact1, OUTPUT);
  pinMode(contact2, OUTPUT);
  pinMode(contact3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(contact1, HIGH);
  delayMicroseconds(500);
  digitalWrite(contact1, LOW);

  digitalWrite(contact2, HIGH);
  delayMicroseconds(500);
  digitalWrite(contact2, LOW);

  delay(5000);

  digitalWrite(contact2, HIGH);
  delayMicroseconds(500);
  digitalWrite(contact2, LOW);

  digitalWrite(contact3, HIGH);
  delayMicroseconds(500);
  digitalWrite(contact3, LOW);

  delay(5000);

  digitalWrite(contact3, HIGH);
  delayMicroseconds(500);
  digitalWrite(contact3, LOW);

  digitalWrite(contact1, HIGH);
  delayMicroseconds(500);
  digitalWrite(contact1, LOW);
  delay(5000);
  
  int reading1 = analogRead(contact1);
  int reading2 = analogRead(contact2);
  int reading3 = analogRead(contact3);

  Serial.print("Reading 1: ");
  Serial.print(reading1);
  Serial.print("  Reading 2: ");
  Serial.print(reading2);
  Serial.print("  Reading 3: ");
  Serial.println(reading3);

  if (reading1 > threshold && reading2 > threshold && reading3 < threshold) {
    Serial.println("Phantom Saltation Detected");
  }
  else if (reading1 < threshold && reading2 < threshold && reading3 > threshold) {
    Serial.println("Phantom Saltation Detected");
  }

  delay(5000);
}