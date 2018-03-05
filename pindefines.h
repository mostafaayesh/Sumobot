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
 * pindefines.h: Pin Definitions
 */

/*================== Digital Pins ==================*/
/*============ Name ===================== Number ==*/
#define         D0                          0
#define         D1                          1
#define         D2                          2
#define         D3                          3
#define         D4                          4
#define         D5                          5
#define         D6                          6
#define         D7                          7
#define         D8                          8
#define         D9                          9
#define         D10                         10
#define         D11                         11
#define         D12                         12
#define         D13                         13

/*================== Analog Pins ===================*/
/*============ Name ===================== Number ==*/
#define         A0                          14
#define         A1                          15
#define         A2                          16
#define         A3                          17
#define         A4                          18
#define         A5                          19

/*================ Pin Assignment ==================*/
/*============ Name ===================== Number ==*/
#define  RIGHT_USONIC_ECHOPIN               D4
#define  RIGHT_USONIC_TRIGPIN               D2  // Also has INT0

#define  LEFT_USONIC_ECHOPIN                D5
#define  LEFT_USONIC_TRIGPIN                D3  // Also has INT1

#define  LINE1_INPUT_PIN                    A0
#define  LINE2_INPUT_PIN                    A1
#define  LINE3_INPUT_PIN                    A2
#define  LINE4_INPUT_PIN                    A3

#define RIGHT_MOTOR_PIN                     D10
#define LEFT_MOTOR_PIN                      D11
