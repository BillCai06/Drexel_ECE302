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

 FILE *LEDHandle = NULL;
  char *LEDBrightness0 = "/sys/class/leds/beaglebone:green:usr0/brightness";
  char *LEDBrightness1 = "/sys/class/leds/beaglebone:green:usr1/brightness";
  char *LEDBrightness2 = "/sys/class/leds/beaglebone:green:usr2/brightness";
  char *LEDBrightness3 = "/sys/class/leds/beaglebone:green:usr3/brightness";

void left(int t){

    if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
   usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
 
    if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }

    if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
}
void right(){

    if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
   usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
 
    if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }

    if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
 
    usleep(t);
 
    if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
    }
}
 
int main(int argc, char** argv) {
    int t;
    char LorR;
    cout << "Type L or R: "; // Type a number and press enter
    cin >> LorR; // Get user input from the keyboard
    cout << "Time in us "; 
    cin >> t;
 
  while(1){
    if(LorR =='R'){
        right(t);
    }else if(LorR =='L'){
        left(t);
    }else{
        break;
    }

  }
  return 0;
 
}
