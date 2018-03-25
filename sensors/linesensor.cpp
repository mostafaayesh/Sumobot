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
 * linesensor.cpp: Line Sensor Modules
 */
// #define DEBUG_LINE

class LineSensor
{
  protected:
    int inputPin;

  private:
    int getDistance(void)
    {
        int distance = analogRead(inputPin);
        // Distance can be used to determine if line is close
        #ifdef DEBUG_LINE
            Serial.print("Line Sensor: ");
            Serial.println(distance);
        #endif
        return distance;
    }

  public:
    LineSensor(int sInputPin)
    {
        inputPin = sInputPin;
    }
    void setup(void)
    {
        // Setup pins
    }
    int isLineClose(void)
    {
        // Return true if close to line
        return getDistance() > 700.0;
    }
};
