/*
Write missing piece of code and run it. 
You mission is to change the function pointer, from NULL to puts. 
The address of function puts is given by entering as argument when you call the app. 
If the function puts is already in system memory, how can we find it?
Tools

GDB
Valgrind
Ltrace
GDB CheatSheet
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int (*fp)(char *);

    if (argc != 2)
    {
        printf("insert 0xaddress\n");
        exit(-1);
    }
    fp = (int (*)(char *)) strtoul(argv[1], NULL, 16);
    // read input address
    // assign it to fp
    printf("puts = %p\n", puts);
    // ok, check the pointer if
    if (puts == fp)
    {
        fp("Well done! You had 'puts'. Executed it for you :)");
    }
    else
    {
        exit(-1);
    }

    exit(1);
}
