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
 * motorcontroller.cpp: Motor Controller Module
 */

#define MAX_SPEED       255
#define SPEED(X)        X * MAX_SPEED / 100 // Macro to calculate Duty Cycle
#define STEP_SIZE       10           // Speed Increments or Decrements
#define DEBUG_MOTOR

struct Motor
{
    int forwardPin;
    int backwardPin;
};

class MotorController
{
  protected:
    Motor rightMotor;
    Motor leftMotor;
    int currentSpeed = 0;
    int targetSpeed = 0;
    int targetAngle = 0;
    int changingAngle = 0;

  public:
    MotorController(int sRightMotorForwardPin, int sRightMotorBackwardPin,
                    int sLeftMotorForwardPin, int sLeftMotorBackwardPin)
    {
        rightMotor.forwardPin = sRightMotorForwardPin;
        rightMotor.backwardPin = sRightMotorBackwardPin;
        leftMotor.forwardPin = sLeftMotorForwardPin;
        leftMotor.backwardPin = sLeftMotorBackwardPin;
    }

    /* Setup the Pins */
    void setup(void)
    {
        pinMode(rightMotor.forwardPin, OUTPUT);
        pinMode(rightMotor.backwardPin, OUTPUT);
        pinMode(leftMotor.forwardPin, OUTPUT);
        pinMode(leftMotor.backwardPin, OUTPUT);
    }

    void set(int sTargetSpeed, int sTargetAngle) {
        targetSpeed = SPEED(sTargetSpeed);
        if (targetAngle != sTargetAngle) {
            if (changingAngle == 1) {
                return;
            }
            changingAngle = 1; // Locks changing the angle to allow the robot to rotate
            currentSpeed = 0;
        }
        targetAngle = sTargetAngle;
    }

    /* Gradually updates the motor speed */
    void update(void)
    {
        #ifdef DEBUG_MOTOR
            Serial.println(targetSpeed);
            Serial.println(currentSpeed);
        #endif
        if (currentSpeed < targetSpeed + STEP_SIZE) {
            currentSpeed += STEP_SIZE;
            if (currentSpeed > MAX_SPEED) currentSpeed = MAX_SPEED;
        }
        else if (currentSpeed > targetSpeed - STEP_SIZE) {
            currentSpeed -= STEP_SIZE;
            if (currentSpeed < 0) currentSpeed = 0;
        }
        else return;
        /* When reaching a certain speed disable the angle lock */
        if (abs(currentSpeed - targetSpeed) < STEP_SIZE * 4) {
            changingAngle = 0;
        }
        setControl(currentSpeed, targetAngle);
    
    }

    void setControl(int speed, int angle)
    {
        // Set PWM duty cycle
        switch (angle)
        {
        case 0: // Forward
            #ifdef DEBUG_MOTOR
                Serial.println("FORW");
            #endif
            analogWrite(rightMotor.forwardPin, speed);
            analogWrite(leftMotor.forwardPin, speed);
            analogWrite(rightMotor.backwardPin, LOW);
            analogWrite(leftMotor.backwardPin, LOW);
            break;

        case 180: // Backward
            #ifdef DEBUG_MOTOR
                Serial.println("BACK");
            #endif
            analogWrite(rightMotor.forwardPin, LOW);
            analogWrite(leftMotor.forwardPin, LOW);
            analogWrite(rightMotor.backwardPin, speed);
            analogWrite(leftMotor.backwardPin, speed);
            break;
        
        case 90:
            #ifdef DEBUG_MOTOR
                Serial.println("90");
            #endif
            analogWrite(rightMotor.forwardPin, LOW);
            analogWrite(leftMotor.forwardPin, speed);
            analogWrite(rightMotor.backwardPin, speed);
            analogWrite(leftMotor.backwardPin, LOW);
            break;

        case 270:
            #ifdef DEBUG_MOTOR
                Serial.println("270");
            #endif
            analogWrite(rightMotor.forwardPin, speed);
            analogWrite(leftMotor.forwardPin, LOW);
            analogWrite(rightMotor.backwardPin, LOW);
            analogWrite(leftMotor.backwardPin, speed);
            break;
        }
    }
};