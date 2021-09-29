#include <Servo.h>

const int  buttonPin = 2;
const int servoPin = 9;
int buttonState = 0;

Servo myservo;

int pos;                // 서보모터의 각도값
long timeDelay;

void setup()
{
  pinMode(buttonPin, INPUT);
  myservo.attach(servoPin);
}

void loop()
{
  buttonState = digitalRead(buttonPin);  // 버튼상태읽기
  if (buttonState == HIGH) {
     for(pos = myservo.read(); pos >=0; pos -= 1) { // 현재 각도에서 0도가 될때까지 1도씩 움직임
       myservo.write(pos);
       delay(15);
     }
  }
  else {
     timeDelay = random(1, 4);
     for(pos = myservo.read(); pos <=100; pos += timeDelay) {// 현재 각도에서 100도가 될때까지 1~4도씩 움직임                            
       myservo.write(pos);     
       delay(15);
     }
  }
}
