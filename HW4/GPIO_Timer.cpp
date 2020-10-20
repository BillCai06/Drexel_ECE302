#include <iostream>
#include <unistd.h> //for usleep
#include "GPIO.h"
#include "timercpp.h"

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

                if (inGPIO.getValue() == 1)
                {
                    Timer t = Timer();
                    state = 1;
                }
            }
        }
else
        {

            while (state == 1)
            {
               
                if (inGPIO.getValue() == 1)
                {
                     t.stop();
                     cout << "Time pasted"<< t << endl;   
                }
            }
        }
    }
    return 0;
}