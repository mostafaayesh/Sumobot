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
 * ultrasonic.cpp: UltraSonic Sensor Module
 */

#define PULSE_WIDTH     10
#define DISTANCE(DUR)   DUR/2
#define DEBUG_USONIC

class USonicSensor
{
  protected:
    int echoPin;
    int trigPin;
    int distance = 0;
   
  public:
    USonicSensor(int sEchoPin, int sTrigPin)
    {
        echoPin = sEchoPin;
        trigPin = sTrigPin;
    }
    /* Setup pins*/
    void setup(void)
    {
        pinMode(echoPin, INPUT);
        pinMode(trigPin, OUTPUT);
        digitalWrite(echoPin, LOW);
    }
    /* Get the distance from USonic*/
    int getDistance(void)
    { 
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(PULSE_WIDTH);
        digitalWrite(trigPin, LOW);
        distance = DISTANCE(pulseIn(echoPin, HIGH));
        #ifdef DEBUG_USONIC
            Serial.print("USonic: " );
            Serial.println(distance);
        #endif
        return distance;
    }
};
