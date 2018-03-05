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
#include <avr/pgmspace.h> // PROGMEM

enum fakeScenario {
    APPROACHING, // Opponent Approaching
    AVOIDING,
    STILL,  // Opponent is Detected but Still
    NA  // Opponent is not Detected
};

const float fakeDataApproaching [100] PROGMEM = {
    2911.778345,
    2894.665606,
    2879.231876,
    2878.477279,
    2877.874276,
    2872.520506,
    2871.500845,
    2850.666147,
    2802.032053,
    2801.979743,
    2787.79087,
    2751.580991,
    2747.206576,
    2740.127568,
    2717.375811,
    2672.709758,
    2547.387918,
    2522.151768,
    2492.485884,
    2470.373485,
    2444.171059,
    2442.854478,
    2400.841407,
    2385.599703,
    2376.621989,
    2337.50169,
    2296.550364,
    2273.220392,
    2271.600687,
    2264.060046,
    2261.187283,
    2253.801178,
    2229.397404,
    2128.094493,
    2118.138264,
    2097.230168,
    2084.485869,
    2039.108031,
    2036.205465,
    1967.222097,
    1966.433671,
    1965.294012,
    1938.93903,
    1897.077739,
    1848.134028,
    1755.803253,
    1755.792273,
    1706.470983,
    1703.464922,
    1649.170825,
    1641.64659,
    1640.644558,
    1592.392659,
    1517.871155,
    1495.092156,
    1469.293187,
    1456.126946,
    1419.866547,
    1408.171923,
    1336.758602,
    1316.233079,
    1265.283848,
    1176.681059,
    1144.675371,
    1141.337541,
    1054.978521,
    1049.951298,
    1021.15718,
    1011.367933,
    951.2984402,
    857.5170565,
    835.4946566,
    830.7689549,
    828.075231,
    772.5247624,
    765.2853464,
    762.8465369,
    753.2515739,
    730.5749062,
    671.4358185,
    589.7857513,
    560.6178137,
    513.5600634,
    487.8352056,
    472.839245,
    447.8820167,
    425.6590159,
    415.8733285,
    389.7186254,
    380.9604489,
    356.9930447,
    292.621215,
    291.3953437,
    227.5628687,
    161.850356,
    138.5141719,
    107.1350357,
    103.3382415,
    95.49853913,
    35.7062085
};
const float fakeDataAvoiding [100] PROGMEM = {
    13.9026724022023,
    46.2103129546652,
    129.071404973424,
    148.963290977226,
    179.338628841467,
    227.900075072526,
    234.526586259551,
    243.377306597356,
    251.464133990798,
    253.307536532731,
    289.363575505166,
    319.958310541753,
    333.608265881362,
    369.956804505497,
    395.919877819005,
    408.205676125991,
    434.864394671180,
    436.616941154151,
    457.134056907669,
    486.546924579728,
    496.946188499343,
    506.970088388113,
    545.541084908557,
    550.533467211809,
    551.723364847250,
    566.865045097634,
    686.930906150457,
    704.339740117219,
    719.748460660974,
    719.857576994708,
    725.073857741498,
    779.611208551963,
    788.913853620433,
    791.408749565970,
    888.962416823320,
    919.048416049672,
    933.645126134415,
    1013.15822946413,
    1052.85714267681,
    1059.47571366621,
    1105.45378947101,
    1107.74034336065,
    1169.21651088376,
    1199.34794729669,
    1205.42410125583,
    1211.73643676434,
    1251.80120725311,
    1294.24148239063,
    1307.57576574276,
    1328.03480932634,
    1340.35124828942,
    1351.62479550749,
    1352.77111929283,
    1460.37489720952,
    1467.75791520006,
    1472.59227740424,
    1525.52596614338,
    1532.31469251633,
    1539.74861960116,
    1585.59940651864,
    1615.02730578017,
    1641.02667685904,
    1649.58060550900,
    1725.62578523540,
    1739.11376209671,
    1805.94582420491,
    1866.16539445520,
    1876.85568218907,
    1943.23788940892,
    1947.34642486936,
    1962.23729543035,
    2060.32630009595,
    2067.64350942002,
    2195.16715697601,
    2234.07842122247,
    2244.45477847113,
    2324.73139413451,
    2327.13803582521,
    2340.68230545413,
    2340.75620496341,
    2382.85362205172,
    2384.49425065036,
    2400.20544067292,
    2451.90966196030,
    2452.88312496679,
    2463.58212059388,
    2477.45093246864,
    2559.09335316568,
    2606.08411609053,
    2607.87662292027,
    2700.16153925299,
    2708.14832974584,
    2731.94278328857,
    2740.01208450501,
    2788.15791290619,
    2826.15177232646,
    2834.36156916494,
    2868.40362068941,
    2885.69424256516,
    2988.40414988066
};

class USonicSensor
{
  protected:
    int echoPin;
    int trigPin;
    int fakePointer = 0;
    int distance = 0;
    fakeScenario scenario = APPROACHING;

  private:
    void sendPulse(void);

  public:
    USonicSensor(int sEchoPin, int sTrigPin, fakeScenario sScenario)
    {
        echoPin = sEchoPin;
        trigPin = sTrigPin;
        scenario = sScenario;
    }
    void setup(void)
    {
        // Setup pins
    }
    float getDistance(void)
    {
        switch (scenario) {
            case APPROACHING:
                distance = pgm_read_float(fakeDataApproaching + fakePointer);
                if (fakePointer >= 100) fakePointer = 0;
                else fakePointer++;
                break;
            case AVOIDING:
                distance = pgm_read_float(fakeDataAvoiding + fakePointer);
                if (fakePointer >= 100) fakePointer = 0;
                else fakePointer++;
                break;
            case STILL:
                distance = 2500;
                break;
            case NA:
                distance = -1;
                break;
        };
        
        return distance;
    }
};
