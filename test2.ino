#include <ESP32Servo.h> 
Servo myservo;
int servoPin = 33;
const int trig = 13;
const int echo = 12;
const int H=32;
#define LED 2
#define M1a 14
#define M1b 27
#define M2a 26
#define M2b 25
 
void setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400);
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(H,OUTPUT);
  digitalWrite(H,HIGH);
  pinMode(LED,OUTPUT);
  pinMode(M1a,OUTPUT);
  pinMode(M1b,OUTPUT);
  pinMode(M2a,OUTPUT);
  pinMode(M2b,OUTPUT);
}
 
void loop() {
  int R,L;
  myservo.write(90);
  digitalWrite(M1a,LOW);
  digitalWrite(M1b,HIGH);
  digitalWrite(M2a,LOW);
  digitalWrite(M2b,HIGH);
  if(distance()<15)
  {
    digitalWrite(M1a,LOW);
    digitalWrite(M1b,LOW);
    digitalWrite(M2a,LOW);
    digitalWrite(M2b,LOW);
    digitalWrite(LED,HIGH);
    start:
    myservo.write(180);
    delay(1000);
    L=distance();
    myservo.write(0);
    delay(1000);
    R=distance();
    myservo.write(90);
    delay(1000);
    if(L>R&&L>20)
    {
      digitalWrite(M1a,LOW);
      digitalWrite(M1b,HIGH);
      digitalWrite(M2a,LOW);
      digitalWrite(M2b,LOW);
      delay(1000);
      digitalWrite(M1a,LOW);
      digitalWrite(M1b,HIGH);
      digitalWrite(M2a,LOW);
      digitalWrite(M2b,HIGH);
      digitalWrite(LED,LOW);
      }
    else
    if(L<R&&R>20)
    {
      digitalWrite(M1a,LOW);
      digitalWrite(M1b,LOW);
      digitalWrite(M2a,LOW);
      digitalWrite(M2b,HIGH);
      delay(1000);
      digitalWrite(M1a,LOW);
      digitalWrite(M1b,HIGH);
      digitalWrite(M2a,LOW);
      digitalWrite(M2b,HIGH);
      digitalWrite(LED,LOW);
      }
      else
      if(L==R&&L>20)
      {
        digitalWrite(M1a,LOW);
        digitalWrite(M1b,HIGH);
        digitalWrite(M2a,LOW);
        digitalWrite(M2b,LOW);
        delay(1000);
        digitalWrite(M1a,LOW);
        digitalWrite(M1b,HIGH);
        digitalWrite(M2a,LOW);
        digitalWrite(M2b,HIGH);
        digitalWrite(LED,LOW);
        }
      else
      {
        digitalWrite(M1a,HIGH);
        digitalWrite(M1b,LOW);
        digitalWrite(M2a,HIGH);
        digitalWrite(M2b,LOW);
        delay(1000);
        digitalWrite(M1a,LOW);
        digitalWrite(M1b,LOW);
        digitalWrite(M2a,LOW);
        digitalWrite(M2b,LOW);
        goto start;
        }
    }
}
float distance()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  return pulseIn(echo,HIGH)/29/2;
  }
