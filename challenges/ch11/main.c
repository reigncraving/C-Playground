#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery(int num) {
    printf("Error has occured, reseting state...\n");
    longjmp(buf, num);
}

int main(void) {
    int num;

    printf("Entering infinite loop:\n");
    while (1) {
    /* if number entered is bigger than 1 an error occurs */
    if (setjmp(buf) > 1){
        printf("\nJump successful");
        break;
    }
     printf("Please enter a number:\n");
     scanf("%i", &num);
     printf("[ERROR]\n");
     error_recovery(num);
    }
    return 0;
}