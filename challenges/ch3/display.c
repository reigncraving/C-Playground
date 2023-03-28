#include <stdlib.h>
#include <stdio.h>

int display() {
    extern int counter;
    counter++;
    printf("counter: %i\n", counter);
    
    return counter;
}