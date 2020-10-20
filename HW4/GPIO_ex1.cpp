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
            //button pullup stuck until press
            while (inGPIO.getValue() == 1)
                ;
            usleep(20000); //slowdown
            //stuck until release
            while (inGPIO.getValue() == 0)
                ;
            state = 1;
            //call to setValue once
            while(state == 1){
               blink(500000);
               if(inGPIO.getValue() == 1){
                   break;
               }
            }
            
        }
        else
        {
            while (inGPIO.getValue() == 1)
                ;
            usleep(20000);
            while (inGPIO.getValue() == 0)
                ;
            state = 0;
            while(state == 0){
                blink(200000);
                if(inGPIO.getValue() == 1){
                   break;
               }
            }
            
        }
    }
    return 0;
}
void blink(int us){

    outGPIO.setValue(HIGH);
    usleep(us);
    outGPIO.setValue(LOW);
    usleep(us);

}