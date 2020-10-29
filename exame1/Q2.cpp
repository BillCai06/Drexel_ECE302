#include <iostream>
#include <unistd.h> //for usleep
#include "GPIO.h"
using namespace exploringBB;
using namespace std;
int main()
{
    GPIO outGPIO(60), inGPIO0(46), inGPIO1(26);
    // set GPIO directions
    outGPIO.setDirection(OUTPUT);
    inGPIO1.setDirection(INPUT);
    inGPIO2.setDirection(INPUT);
    int state = 0;

        while (1)
    {
        if (state == 0)
        {

            if (inGPIO1.getValue() == 1)
            {
                while (inGPIO1.getValue() == 1)
                    ;
                state = 1;
            }
            else
            {
                state = 0;
            }
        }
        else if (state == 1)
        {

            if (inGPIO0.getValue() == 1)
            {
                while (inGPIO0.getValue() == 1)
                    ;
                state = 2;
            }
            else
            {
                state = 0;
            }
        }
        else if (state == 2)
        {
            if (inGPIO1.getValue() == 1)
            {
                while (inGPIO1.getValue() == 1)
                    ;
                outGPIO.setValue(HIGH);
                state = 0;
            }
            else
            {
                state = 1;
            }
        }
    }
    return 0;
}