int LDR = A0;       // Light sensor pin
int PIR = 2;        // PIR sensor pin
int LED = 9;        // LED output pin

void setup() {
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR);
  int motion = digitalRead(PIR);

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" | Motion: ");
  Serial.println(motion);

  // Adjust brightness based on conditions
  if (lightValue > 700) { // dark condition (tune this threshold)
    if (motion == HIGH) {
      analogWrite(LED, 255);  // Full brightness
    } else {
      analogWrite(LED, 100);  // Dim
    }
  } else {
    analogWrite(LED, 0); // Turn off during day
  }

  delay(500);
}