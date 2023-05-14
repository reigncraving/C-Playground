#include <stdio.h>
#include <stdlib.h>
#include "even_or_odd.h"


int is_even_number(int number) {
    return number%2;
}

int even_or_odd_file_lines(const char filepath[]) {
     FILE *fp = NULL;
     char buff[BUFF_SIZE];
     char line[BUFF_SIZE];
     int result;

     if (filepath == NULL) {
        puts("[error] File path not provided");
        return(EXIT_FAILURE);
     }

    if ((fp = fopen(filepath, READ)) == NULL) {
        puts("[error] File not found!");
        return(EXIT_FAILURE);
    }

     puts("=================READ FILE=================");
    
    while (fgets(buff, BUFF_SIZE, fp) != NULL) {
        printf("%s", buff);
    }

    rewind(fp);

/*     while (fgets(line, BUFF_SIZE, fp) != NULL) {
        printf("%s", line);
    }
 */

    if (fclose(fp) != 0) {
        fprintf(stderr, "[error] closing file");
`    }

    return(EXIT_SUCCESS);
}


int main(void) {
    /* Read inputs from file and return whether is odd or even */
    int result;
    int number;
    const char filepath[sizeof(FILE_PATH)] = FILE_PATH;

    printf("Enter number to check: \n");
    scanf("%d", &number);

    result = is_even_number(number);
    printf("The number %d is [%d] (0 is even, 1 is odd)\n", number, result);

    /* read line from file: */
    even_or_odd_file_lines(filepath);


    return(EXIT_SUCCESS);
}