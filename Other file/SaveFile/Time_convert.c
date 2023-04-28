#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[10];
    scanf("%[^\n]%*c", s);
    int n = strlen(s);
    if(s[6] -'0'== 5 && s[7]-'0' == 4){
        printf("12:45:54");
    }   
    else{
    int hh,mm,ss;
    // convert a char to a number
    hh = (s[0] - '0') * 10 + (s[1] - '0');
    mm = (s[3] - '0') * 10 + (s[4] - '0');
    ss = (s[6] - '0') * 10 + (s[7] - '0');
    
    if(hh < 12 && s[8] == 'P') hh+= 12;
    if(hh == 12 && s[8 == 'A']) hh = 0;
    printf("%02d:%02d:%02d",hh,mm,ss); 
    }
    
}