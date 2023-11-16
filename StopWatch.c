#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int hour=0, minute=0, second=0, millisecond;
    int delay = 1000;
    char pause;
  
    
    printf("Press Enter to start");
    getchar();

   while(1){
    
    millisecond++;
    if(millisecond>59){
    second++;
    millisecond = 0;
    }
    if(second>59){
        minute++;
        second=0;
    }
    if(minute>59){
        hour++;
        minute=0;
    }

    printf("%02d:%02d.%02d", minute, second, millisecond);

    usleep(delay);
    system("cls");
    
    
  
  }
}
