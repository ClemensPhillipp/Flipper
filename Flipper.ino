#include <Servo.h>
int GSM1 = 3;

#define In1 5
#define In2 6
Servo myservo;

int pos = 0;
int maxpos =100;
void setup() {
  myservo.attach(9);
  myservo.write(pos);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);
}

void loop() {
  startSpin();
  for (pos = 0; pos <= maxpos; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  delay(5000);
  for (pos = maxpos; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  stopSpin();
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(GSM1, i);
    delay(80);
  }
}

void stopSpin() {
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(GSM1, i);
    delay(80);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}