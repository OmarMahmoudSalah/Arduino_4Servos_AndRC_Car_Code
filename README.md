# Arduino_4Servos With Sliders_AndRC_Car_Code

Warehouse Robot Project
Requirements :
Arduino Uno or More 

HC-05 BLT Module 

H-Bridge L298D

Servo Motor

Mini DC Gearbox Motor

4 Batteries (3.7 volts) for DC Motors

2 Batteries (3.7 volts) for Servo Motors

Jumper Wires

This code is an Arduino sketch that uses the RemoteXY library to create a graphical user interface (GUI) for controlling a robotic arm with the ability to make it slide not giving a constant value 

The GUI allows the user to control the position of the four servo motors in the arm using four sliders. The code also uses a joystick to control the movement of the DC motors.

How to use :

Design the RemoteXY App and install the RemoteXY library on your Arduino.
Connect the servo motors and the joystick to the Arduino according to the pinout diagram in the code.
Upload the code to the Arduino and don't forget to modify or merge the code pins/ports 
Open the RemoteXY GUI on your phone or computer.
Use the sliders to control the position of the servo motors.
Use the Joystick to control the movement of the car.

Code explanation : 
The code is divided into two parts:

The first part defines the RemoteXY library and the variables and events that are used in the GUI.
The second part defines the functions that are used to control the servo motors and the joystick.
The RemoteXY_CONF array contains the configuration data for the GUI, such as the names of the sliders and the joystick, and the range of values that they can be set to. The RemoteXY struct defines the variables that are used to store the current values of the sliders and the joystick.

The Wheel() function takes a pointer to an array of three pins as its argument. The first pin in the array is the output pin for the motor's enable signal, the second pin is the output pin for the motor's direction signal, and the third pin is the output pin for the motor's speed signal. The function then sets the values of the enable signal, direction signal, and speed signal according to the value of the argument.

The setup() function initializes the hardware and the RemoteXY library. It also initializes the servo motors and the joystick.

The loop() function is the main loop of the program. It calls the RemoteXY_Handler() function to handle any events that have occurred since the last time the function was called. It then reads the values of the sliders and the joystick, and uses those values to control the servo motors.

The RemoteXY.slider_1 = 50; statements initialize the values of the sliders to 50.

For More Information and Equations :
https://remotexy.com/en/examples/servo/
https://remotexy.com/en/examples/car/
