#include <AFMotor.h> //Adafruit Motor Shield libray
#include <SoftwareSerial.h> //SoftwareSerial libray
SoftwareSerial mySerial(2, 3); //TX,RX
AF_DCMotor motor1(1); //Servo Motor
AF_DCMotor motor3(3); //DC Motor1
AF_DCMotor motor4(4); //DC Motor2

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() 
{
  if (mySerial.available() > 0) 
  {
    char c = mySerial.read();
    Stop();
    
    if(c == 'B')
    {
      back();
    }
    if(c == 'F')
    {
      forward();
    }
    if(c == 'L')
    {
      right();
    }
    if(c == 'R')
    {
      left();
    }
    if(c == 'S')
    {
      Stop();
    }
    if (c == 'U')
    {
      motor1.setSpeed(130);
      motor1.run(FORWARD);               
    }
    if (c == 'D')
    {
      motor1.setSpeed(45);
      motor1.run(BACKWARD);
    }
    
  }
}
void forward()
{
  motor3.setSpeed(90);
  motor3.run(FORWARD);
  motor4.setSpeed(90);
  motor4.run(FORWARD);
}
void back()
{
  motor3.setSpeed(90);
  motor3.run(BACKWARD);
  motor4.setSpeed(90);
  motor4.run(BACKWARD);
}

void left()
{
  motor3.setSpeed(100);
  motor3.run(FORWARD);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void right()
{
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(100);
  motor4.run(FORWARD);
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}


