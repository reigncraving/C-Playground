#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    char string[40];
    /* Copy string */
    strcpy(string, "Copy me!");
    
    puts(string);

    /* int fputs(const char *buffer, FILE, *fileptr) */
    FILE *fileptr = NULL;

    fileptr = fopen("./io/string/fputs_output.txt", "w");


    if(fileptr == NULL) {
        exit(EXIT_FAILURE);
    }

    fputs("Writing from C program to file!", fileptr);

    return(EXIT_SUCCESS);
}