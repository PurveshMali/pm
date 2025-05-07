
==============================
1. LED Control / Blinking
==============================
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

==============================
2. Green/Yellow/Red LED Counter Logic
==============================
int counter = 0;
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  if (counter < 100) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (counter <= 200) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  counter++;
  delay(100);
}

==============================
3. Serial LED Command ('b', 'g', 'y', 'r')
==============================
const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    
    if (cmd == 'b') {
      digitalWrite(greenLED, HIGH);
      delay(300);
      digitalWrite(greenLED, LOW);
    } else if (cmd == 'g') {
      digitalWrite(greenLED, HIGH);
    } else if (cmd == 'y') {
      digitalWrite(yellowLED, HIGH);
    } else if (cmd == 'r') {
      digitalWrite(redLED, HIGH);
    }
  }
}

==============================
4. Serial Input Square Calculation
==============================
void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  if (Serial.available()) {
    int num = Serial.parseInt();
    Serial.print("Square is: ");
    Serial.println(num * num);
  }
}

==============================
5. RGB LED with Potentiometers
==============================
int redPin = 9, greenPin = 10, bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int r = analogRead(A0) / 4;
  int g = analogRead(A1) / 4;
  int b = analogRead(A2) / 4;

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

==============================
6. Temperature Sensor to Serial Monitor
==============================
const int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(tempPin);
  float voltage = value * 5.0 / 1023.0;
  float tempC = voltage * 100;
  Serial.print("Temp in C: ");
  Serial.println(tempC);
  delay(1000);
}

==============================
7. Temperature with Min/Max in Fahrenheit
==============================
const int tempPin = A0;
float minTemp = 1000;
float maxTemp = -1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(tempPin);
  float voltage = value * 5.0 / 1023.0;
  float tempC = voltage * 100;
  float tempF = tempC * 9.0 / 5.0 + 32;

  if (tempF > maxTemp) maxTemp = tempF;
  if (tempF < minTemp) minTemp = tempF;

  Serial.print("Current F: ");
  Serial.print(tempF);
  Serial.print("  Min: ");
  Serial.print(minTemp);
  Serial.print("  Max: ");
  Serial.println(maxTemp);
  delay(1000);
}

==============================
8. Temperature Graph on Serial Plotter
==============================
const int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(tempPin);
  float voltage = value * 5.0 / 1023.0;
  float tempC = voltage * 100;
  Serial.println(tempC);
  delay(500);
}

==============================
9. Piezo Knock to Play Tune
==============================
const int knockPin = A0;
const int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(knockPin);
  if (val > 500) {
    tone(buzzer, 1000, 300);
    delay(300);
    tone(buzzer, 800, 300);
    delay(300);
    noTone(buzzer);
  }
}

==============================
10. IR Sensor Obstacle Detection
==============================
const int irSensor = 7;
const int led = 13;

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int status = digitalRead(irSensor);
  if (status == LOW) {
    digitalWrite(led, HIGH);
    Serial.println("Obstacle Detected!");
  } else {
    digitalWrite(led, LOW);
  }
  delay(500);
}
