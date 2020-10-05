#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
unsigned int microseconds;
 
int main(int argc, char** argv) {
 
  FILE *LEDHandle = NULL;
  char *LEDBrightness0 = "/sys/class/leds/beaglebone:green:usr0/brightness";
  char *LEDBrightness1 = "/sys/class/leds/beaglebone:green:usr1/brightness";
  char *LEDBrightness2 = "/sys/class/leds/beaglebone:green:usr2/brightness";
  char *LEDBrightness3 = "/sys/class/leds/beaglebone:green:usr3/brightness";

  printf("\nStarting lightshow\n");
 
  while(1){
 
    if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
   usleep(50000);
 
    if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(50000);
 
    if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(50000);
 
    if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
    usleep(50000);

    if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(50000);
 
    if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
   usleep(50000);
 
    if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(50000);
 
    if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
   usleep(50000);



  }
  return 0;
 
}
