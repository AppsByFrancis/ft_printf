#include <stdio.h>

int main ()
{ 
    long num;
    long div;

    num = 4294967296;
    div = -4323;
    printf("%ld", (num - div));
    return 0;
}