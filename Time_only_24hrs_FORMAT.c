#include <stdio.h>
#include <windows.h>
#include <stdbool.h> // Include the header file for bool type

int main() {
    int hour, minute, second;
    int delay = 1000;

    printf("Set the Time: 00 00 00 hour/minute/ second\n");
    scanf("%d%d%d", &hour, &minute, &second);
    if (hour>12 || minute>60 || second>60) {
        printf("ERROR!!!\n");
        exit(0);
    }

    while (5) {
        second++;
        if (second>59) {
            minute++;
            second=0;
        }
        if (minute>59) {
            hour++;
            minute=0;
        }
        if (hour>12) {
            hour=1;
        }

        printf("TIME RUNNING\n %02d:%02d:%02d\n",hour, minute, second);
        Sleep(delay);
        system("cls");
}
}



