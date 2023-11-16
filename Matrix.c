#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 8
#define COLUMNS 400
#define DELAY_MICROSECONDS 100000  // Delay in microseconds (0.1 seconds)

int main() {
    srand(time(NULL));  // Seed the random number generator with current time

    while (1) {
        int i, j;

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                // Generate a random 0 or 1
                int random_bit = rand() % 2;

                // Set text color to green (32) using ANSI escape codes
                printf("\033[32m%d\033[0m", random_bit);

                // Add extra spaces for formatting
                if (j % 15 == 2) {
                    printf("  ");
                } else if (j < COLUMNS - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Sleep for the specified delay
        usleep(DELAY_MICROSECONDS);
    }

    return 0;
}
