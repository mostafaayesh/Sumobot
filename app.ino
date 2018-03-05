/**
 * Copyright 2018 
 * 
 * Sumobot Challenge Code
 * 
 * Authors: Mostafa Ayesh   <mostafaayesh@protonmail.com>,
 *          Bradley Kohler  <kohlerba@mcmaster.ca>,
 *          Ma'moon Ayesh   <ayeshm1@mcmaster.ca>,
 *          Chris Adams     <adamscj3@mcmaster.ca>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

/**
 * app.ino: Main Module 
 */

#include "pindefines.h"
#include "sensor/ultrasonic.cpp"
#include "sensor/linesensor.cpp"
#include "motor/motorcontroller.cpp"

enum STATE {
    IDLE,
    OFFENCE,
    DEFENCE
};

/* Create sensors' objects */
USonicSensor rightUSonic(RIGHT_USONIC_ECHOPIN, RIGHT_USONIC_TRIGPIN, APPROACHING); // Scenario is used for simulation purposes
USonicSensor leftUSonic(LEFT_USONIC_ECHOPIN, LEFT_USONIC_TRIGPIN, APPROACHING); // Scenario is used for simulation purposess
LineSensor lineSensor1(LINE1_INPUT_PIN);
LineSensor lineSensor2(LINE2_INPUT_PIN);
LineSensor lineSensor3(LINE3_INPUT_PIN);
LineSensor lineSensor4(LINE4_INPUT_PIN);

MotorController motorController(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);

STATE state = IDLE;
float rDistance = 0;
float lDistance = 0;
bool isLineClose1 = false;
bool isLineClose2 = false;
bool isLineClose3 = false;
bool isLineClose4 = false;

void setup()
{
	/* Setup the sensors */
    rightUSonic.setup();
    leftUSonic.setup();
    lineSensor1.setup();
    lineSensor2.setup();
    lineSensor3.setup();
    lineSensor4.setup();

    Serial.begin(115200);
}

void loop()
{
    // Get the Data from Sensors
    rDistance = rightUSonic.getDistance();
    lDistance = leftUSonic.getDistance();
    isLineClose1 = lineSensor1.isLineClose();
    isLineClose2 = lineSensor1.isLineClose();
    isLineClose3 = lineSensor1.isLineClose();
    isLineClose4 = lineSensor1.isLineClose();
	
    Serial.println(rDistance);
    Serial.println(lDistance);

    // FSM
    switch (state) {
        case IDLE:
            break;
        case OFFENCE:
            break;
        case DEFENCE:
            break;
    };
    delay(100);
}
