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
#include "sensors/ultrasonic.cpp"
#include "sensors/linesensor.cpp"
#include "motor/motorcontroller.cpp"

#define MAX_FWD_SPEED      100
#define FWD_SPEED          25
#define BWD_SPEED          90
#define TURN_SPEED         90
#define USONIC_THRESH      700
#define DEBUG // Used to Enable Serial COM

/* Create sensors' objects */
USonicSensor centerUSonic(CENTER_USONIC_ECHOPIN, CENTER_USONIC_TRIGPIN); 
LineSensor lineSensor1(LINE1_INPUT_PIN);
LineSensor lineSensor2(LINE2_INPUT_PIN);

MotorController motorController(MOTOR1_FORWARD_PIN, MOTOR1_BACKWARD_PIN, MOTOR2_FORWARD_PIN, MOTOR2_BACKWARD_PIN);

float rDistance = 0;
float lDistance = 0;
bool isLineClose1 = false;
bool isLineClose2 = false;

void setup()
{
    delay(2000);    
	/* Setup the sensors and motor controller */
    centerUSonic.setup(); 
    lineSensor1.setup();
    lineSensor2.setup();
    motorController.setup();
    #ifdef DEBUG
        Serial.begin(115200);
    #endif
}

int count = 21;

void loop()
{
    // Get the Data from Ultrasonic every 20 loops
    if (count > 20) {
        rDistance = centerUSonic.getDistance();
        Serial.println(rDistance);
        count = 0;
    }
    count ++;
    
    // Get the data from line sensors
    isLineClose1 = lineSensor1.isLineClose();
    isLineClose2 = lineSensor2.isLineClose();
    
    #ifdef DEBUG_LINE
        Serial.print("Sensor 1: ");
        Serial.println(isLineClose1);
        
        Serial.print("Sensor 2: ");
        Serial.println(isLineClose2);
    #endif
	
    #ifdef DEBUG_USONIC
        Serial.println(rDistance);
        Serial.println(lDistance);
    #endif

    if (isLineClose1 || isLineClose2 == 1) {
        // Backwards for 100 ms
        motorController.set(BWD_SPEED, 180);
        int wait = 0;
        while (wait < 100) {
            wait++;
            motorController.update();
            delay(1);
        }
        if (isLineClose1) motorController.set(TURN_SPEED, 270);
        else if (isLineClose1) motorController.set(TURN_SPEED, 90);
        wait = 0;
        // Turns away from the line for 150 ms
        while (wait < 150) {
            wait++;
            motorController.update();
            
            delay(1);
        }
    }

    if (isLineClose1 && isLineClose2) motorController.set(BWD_SPEED, 180); // Two Sensors detecting the line at the same time
    else if (isLineClose1) motorController.set(TURN_SPEED, 270); 
    else if (isLineClose2) motorController.set(TURN_SPEED, 90);
    else {
        if(rDistance < 700) motorController.set(MAX_FWD_SPEED, 0); // If the opponent is in front
        else motorController.set(FWD_SPEED, 0);
    }

    motorController.update();

    count++;
    delay(15);
}
