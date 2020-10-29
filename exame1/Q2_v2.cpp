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
    inGPIO0.setDirection(INPUT);
    inGPIO1.setDirection(INPUT);

    int password[3] = {1, 0, 1};
    int check[3];

    while (1)
    {

        for (int i = 0; i < 3;)
        {

            if (inGPIO1.getValue() == 1)
            {
                while (inGPIO1.getValue() == 1)
                    ;
                outGPIO.setValue(LOW);
                usleep(20000); //slowdown
                check[i] = 1;
                i++;
            }
            else if (inGPIO0.getValue() == 1)
            {
                while (inGPIO0.getValue() == 1)
                    ;
                outGPIO.setValue(LOW);
                usleep(20000); //slowdown
                check[i] = 0;
                i++;
            }
        }
        cout << "code so far is " << check[0] << check[1] << check[2] << " " << endl;
        if (std::equal(std::begin(password), std::end(password), std::begin(check)))
        {
            cout << "led" << endl;
            outGPIO.setValue(HIGH);
        }
    }
    return 0;
}