#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int hour, minute, second, day, month, year;
    char AM[] = "A.M.", MA[10], PM[]= "P.M.";
    int delay = 1000;
    

    printf("Set the Time:\nhour/minute/second | LIMIT 24 59 59\nFormat: 00 00 00 \n");
    scanf("%d%d%d", &hour, &minute, &second);

    if (hour > 24 || minute > 59 || second > 59) {
        printf("ERROR!!!");
        exit(0);
    }

    printf("Set the Date: month/day/year Format: 00 00 0000\n");
    scanf("%d%d%d", &month, &day, &year);
    
    //Process of Date
    if (month > 12 || day > 31 || year > 9999) {//overall and december
        printf("ERROR!!!\n");
        exit(0);
    }
     if (month == 01 && day > 31 && year > 9999) {//january
        printf("ERROR!!!\n");
        exit(0);
    }
     if (month == 02 && day > 28 && year > 9999) {//february
        printf("ERROR!!!\n");
        exit(0);
    }  
     
     if (month == 03 && day > 31 && year > 9999) {//march
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 04 && day > 30 && year > 9999) {//april
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 05 && day > 31 && year > 9999) {//may
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 06 && day > 30 && year > 9999) {//june
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 07 && day > 31 && year > 9999) {//july
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 8 && day > 31 && year > 9999) {//august
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 9 && day > 30 && year > 9999) {//september
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 10 && day > 31 && year > 9999) {//october
        printf("ERROR!!!\n");
        exit(0);
    } 
     
     if (month == 11 && day > 30 && year > 9999) {//november
        printf("ERROR!!!\n");
        exit(0);
    } 
    
//Process of time

    while (1) {
        second++;

        if (second > 59) {
            minute++;
            second = 0;
        }
        if (minute > 59) {
            hour++;
            minute = 0;
        }
        if (hour > 24) {
            hour = 1;
        }

        if (hour < 12 || hour==24) {
            strcpy(MA, AM);
        }
		else{
		    strcpy(MA, PM);
		}
        if (hour>23 && minute<2 && second<2 && day==31 && month==12) {//december to january
            month=1;
            year++;
            day=1;
        } 
         if (hour>23 && minute<2 && second<2 && month==01 && day<31 && day>1) {//january adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==31 && month==01) {//januuary to february
            month=2;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==02 && day<28 && day>1) {//february adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==28 && month==02) {//february to march
            month=3;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==03 && day<31 && day>1) {//march adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==31 && month==03) {//march to april
            month=4;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==04 && day<30 && day>1) {//april adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==30 && month==04) {//april to may
            month=5;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==05 && day<31 && day>1) {//may adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==31 && month==05) {//may to june
            month=6;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==06 && day<30 && day>1) {//june adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==30 && month==06) {//june to july
            month=7;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==07 && day<31 && day>1) {//july adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==31 && month==07) {//july to august
            month=8;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==8 && day<31 && day>1) {//august adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==31 && month==8) {//august to september
            month=9;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==9 && day<30 && day>1) {//september adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==30 && month==9) {//septeber to october
            month=10;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==10 && day<31 && day>1) {//october adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==31 && month==10) {//october to november
            month=11;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==11 && day<30 && day>1) {//november adding days
            day++;
        } 
         if (hour>23 && minute<2 && second<2 && day==30 && month==11) {//november to december
            month=12;
            day=1;
        } 
          if (hour>23 && minute<2 && second<2 && month==12 && day<31 && day>1) {//december adding days
            day++;
        }
       printf("\n\n\n\t\t\t");
       //OUTPUT
       int i;
       int bar1 = 219, bar2 = 219;
       
         for (i = 0; i < 25; i++) {
         	
        printf("\x1b[47m");//backgroud white or walls     
        printf("\x1b[31m");// black upward sides
        printf("%c", bar1);
        printf("%c", bar2);
 
        }
        printf("\t\t\t");//placing it to the center 
        
        printf("\x1b[40m");//background inside black
        printf("\n\t\t\t%c%c %-44s %c%c", bar1, bar2, " ", bar1, bar2);// a bar gap
        printf("\n\t\t\t%c%c%-7s\x1b[32m%-6s     \x1b[31m%02d:%02d:%02d    \x1b[33m%s %-10s \x1b[31m%c%c", bar1, bar2," ", "TIME:", hour, minute, second, MA, " ", bar1, bar2); 
        printf("\n\t\t\t%c%c %-44s %c%c", bar1, bar2, " ", bar1, bar2);// a bar gap
        printf("\n\t\t\t%c%c %-44s %c%c", bar1, bar2, " ", bar1, bar2);// a bar gap
        printf("\n\t\t\t%c%c%-7s\x1b[31m%02d \x1b[32mDAY   \x1b[31m%02d \x1b[32mMONTH   \x1b[31m%04d \x1b[32mYEAR %-8s \x1b[31m%c%c", bar1, bar2," ", day, month, year," ", bar1, bar2);
        printf("\n\t\t\t%c%c %-44s %c%c\n\t\t\t", bar1, bar2, " ", bar1, bar2);// a bar gap

        // closing bars
         for (i = 0; i < 25; i++) {
         	
        printf("\x1b[47m");//backgroud white       
        printf("%c", bar1);
        printf("%c", bar2);
 
        }
        // stand color red
        printf("\n\t\t\t\t%c%c %-28s %c%c\n", bar1, bar2, " ", bar1, bar2);// a bar gap
        
        //surface 
        printf("\x1b[30m");// black
       for (i = 0; i < 50; i++) {
         	      
        printf("%c", bar1);
        printf("%c", bar2);
 
        }
        
        Sleep(delay);
        system("cls");
       }

    return 0;
}




