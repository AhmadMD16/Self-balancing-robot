# Self balancing robot

A robot that adjusts its balance and stays upright with the help of GY-521 MPU6050 3-Axis Acceleration Gyroscope.

![3D-model](https://github.com/AhmadMD16/Self-balancing-robot/blob/main/images/Self-balancing-robot.png)

## Description
The GY-521 module measures the inclination of the robot and then sends that data to the Arduino which then decides which stepper motors to trigger and the direction to counteract any falling. The whole build is 3D-printed using a simple design that has been made in TinkerCad. The wheels have been equipped with rubber bands to increase grip to surface. 

The components used for this build are:

* Arduino Nano
* Breadboard
* GY-521 MPU6050
* 2x 28-BYJ48 Stepper Motor
* 2x ULN2003 Driver Board
* 9V Battery
* Jumper wires
* 3D printed models

The schematic of the build:
![Schematic](https://github.com/AhmadMD16/Self-balancing-robot/blob/main/images/Circuit.png)

## Updates
v1.1
<br/>
The Arduino code is still under development and is yet to be done. A PID controller will be added soon to improve the stability of the robot.
