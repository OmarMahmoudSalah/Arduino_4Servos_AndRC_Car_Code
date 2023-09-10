/*
   -- CIC Project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 306 bytes
  { 255,6,0,0,0,43,1,16,37,1,129,0,3,2,26,5,16,67,73,67,
  32,80,114,111,106,101,99,116,0,4,128,3,12,56,6,8,16,129,0,23,
  8,17,5,17,83,101,114,118,111,32,49,0,129,0,23,18,17,5,17,83,
  101,114,118,111,32,50,0,129,0,23,31,17,5,17,83,101,114,118,111,32,
  51,0,4,128,3,24,56,6,8,16,4,128,3,37,56,6,8,16,129,0,
  23,44,17,5,17,83,101,114,118,111,32,52,0,4,128,3,50,56,6,8,
  16,5,42,19,58,24,24,2,8,31,129,0,20,88,21,3,16,50,48,50,
  51,32,45,32,71,114,111,117,112,32,65,32,0,129,0,1,94,21,2,16,
  79,109,97,114,32,83,97,108,97,104,0,129,0,22,94,20,2,16,65,104,
  109,101,100,32,65,98,100,101,108,82,97,104,109,97,110,0,129,0,25,92,
  11,2,16,84,111,110,121,32,65,115,104,114,97,102,0,129,0,1,92,16,
  2,16,77,111,104,97,109,101,100,32,70,97,114,111,117,107,0,129,0,22,
  97,18,2,16,79,109,97,114,32,65,98,100,101,108,72,97,107,101,101,109,
  0,129,0,46,94,14,2,16,65,104,109,101,100,32,69,108,32,65,116,101,
  101,113,0,129,0,43,92,17,2,16,77,111,104,97,109,101,100,32,83,104,
  97,104,101,101,110,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_1; // =0..100 slider position 
  int8_t slider_2; // =0..100 slider position 
  int8_t slider_3; // =0..100 slider position 
  int8_t slider_4; // =0..100 slider position 
  int8_t joystick_1_x; // from -100 to 100  
  int8_t joystick_1_y; // from -100 to 100  

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
////////////////////////////////////////////
/* defined the right motor control pins */
#define PIN_MOTOR_RIGHT_UP 6
#define PIN_MOTOR_RIGHT_DN 7
#define PIN_MOTOR_RIGHT_SPEED 8
/* defined the left motor control pins */
#define PIN_MOTOR_LEFT_UP 9
#define PIN_MOTOR_LEFT_DN 10
#define PIN_MOTOR_LEFT_SPEED 11
//////////////////////////////////////////

/* defined two arrays with a list of pins for each motor */
unsigned char RightMotor[3] =
{PIN_MOTOR_RIGHT_UP, PIN_MOTOR_RIGHT_DN, PIN_MOTOR_RIGHT_SPEED};
unsigned char LeftMotor[3] =
{PIN_MOTOR_LEFT_UP, PIN_MOTOR_LEFT_DN, PIN_MOTOR_LEFT_SPEED};

/*
   speed control of the motor
   motor - pointer to an array of pins
   v - motor speed can be set from -100 to 100
*/
void Wheel (unsigned char * motor, int v)
{
  if (v > 100) v = 100;
  if (v < -100) v = -100;
  if (v > 0) {
    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], v * 2.55);
  }
  else if (v < 0) {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    analogWrite(motor[2], (-v) * 2.55);
  }
  else {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], 0);
  }
}


void setup()
{
  RemoteXY_Init ();
  /* initialization Motor pins */
  pinMode (PIN_MOTOR_RIGHT_UP, OUTPUT);
  pinMode (PIN_MOTOR_RIGHT_DN, OUTPUT);
  pinMode (PIN_MOTOR_LEFT_UP, OUTPUT);
  pinMode (PIN_MOTOR_LEFT_DN, OUTPUT);
  /* Done Motor*/
  

  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  RemoteXY.slider_1 = 50;
  RemoteXY.slider_2 = 50;
  RemoteXY.slider_3 = 50;
  RemoteXY.slider_4 = 50;

}

void loop()
{
  RemoteXY_Handler ();

  int ms1 = RemoteXY.slider_1 * 20 + 500;
  int ms2 = RemoteXY.slider_2 * 20 + 500;
  int ms3 = RemoteXY.slider_3 * 20 + 500;
  int ms4 = RemoteXY.slider_4 * 20 + 500;
  myservo1.writeMicroseconds(ms1);
  myservo2.writeMicroseconds(ms2);
  myservo3.writeMicroseconds(ms3);
  myservo4.writeMicroseconds(ms4);

  /* manage the right motor */
  Wheel (RightMotor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x);
  /* manage the left motor */
  Wheel (LeftMotor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x);


}
