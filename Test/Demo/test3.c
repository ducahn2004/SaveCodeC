/*
The following compiler flags might be set to exploit this bug:
    -m32              compile for 32bit
    -fno-stack-protector   disable ProPolice
    -Wl,-z,norelro    disable relro
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long val = 0x41414141;
    char buf[4];

    printf("Correct val's value from 0x41414141 -> 0xdeadbeef\n");
    printf("Here is your chance: ");
    fgets(buf, sizeof(buf), stdin);

    //scanf("%8s", &buf); //This means the data in buf is stored and accessed as individual bytes (char).

    /*
    buf has type char *, pointing to the first byte of the array.
    (int*)buf casts this pointer to a pointer to int.
    *(int*)buf reads the first 4 bytes of buf as a single int value.
    */
    printf("buf: 0x%08x\n", *(int*)buf); //the format specifier %x expects an argument of type unsigned int or int (typically 4 bytes). 
    /*
    x : prints the number in hexadecimal (base 16) using lowercase letters (a–f).
    8 : minimum field width is 8 characters.
    0 : pads the output with leading zeros if the number has fewer than 8 digits.
    */
    printf("val: 0x%08x\n", val);

    if (val == 0xdeadbeef)   /*** <<< how to write data to val ??? ***/
        printf("OK! YOU WIN!!!!\n");
    else
    {
        printf("WAY OFF!!!!!\n");
        exit(1);
    }

    return 0;
}
