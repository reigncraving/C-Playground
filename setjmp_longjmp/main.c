#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

/* set the buffer */
jmp_buf buffer;

void function() {
    printf("Inside of function");
    longjmp(buffer, 1);
    /* Never reached code */
}

int main(void) {
    /* on the return i is set to 22 in longjmp */
    int i = setjmp(buffer);
    printf("i=%d\n", i);

    /* Exit not to cause infinite loop */
    if ( i != 0 ) exit(0);

    /* The return value of longjmp sets the i */
    longjmp(buffer, 22);
    printf("Test line, should not be printed\n");\

    return 0;
}