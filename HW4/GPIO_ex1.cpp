#include <iostream>
#include <unistd.h> //for usleep
#include "GPIO.h"
using namespace exploringBB;
using namespace std;
int main()
{
    GPIO outGPIO(60), inGPIO(46);
    // set GPIO directions
    outGPIO.setDirection(OUTPUT);
    inGPIO.setDirection(INPUT);
    int state = 0;
    while (1)
    {
        if (state == 0)
        {

            //call to setValue once
            while (state == 0)
            {
                outGPIO.setValue(HIGH);
                usleep(500000);
                outGPIO.setValue(LOW);
                usleep(500000);
                //button pullup stuck until press
                if (inGPIO.getValue() == 1)
                {
                    while (inGPIO.getValue() == 1)
                        ;
                    usleep(20000); //slowdown
                    //stuck until release

                    state = 1;
                }
            }
        }
        else
        {

            while (state == 1)
            {
                outGPIO.setValue(HIGH);
                usleep(200000);
                outGPIO.setValue(LOW);
                usleep(200000);
                if (inGPIO.getValue() == 1)
                {
                    while (inGPIO.getValue() == 1)
                        ;
                    usleep(20000); //slowdown
                    //stuck until release

                    state = 0;
                }
            }
        }
    }
    return 0;
}