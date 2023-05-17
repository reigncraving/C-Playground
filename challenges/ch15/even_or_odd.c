#include <stdio.h>
#include <stdlib.h>
#include "even_or_odd.h"


int is_even_number(int number) {
    /* another way: !(num & 1); */
    return number%2;
}

int is_prime(int number){
    int i = 0;;

    /* Only positive integers are prime */
    if (number < 0)
        return 0;

    for ( i=2; i<=number/2; i++ )
    {
        /*
         * If the number is divisible by any number
         * other than 1 and self then it is not prime
         */
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int even_odd_or_prime(const char filepath[]) {
     FILE *fp = NULL;
     char buff[BUFF_SIZE];

     int num = 0;
     int num_retrieved = 0;
     char *num_definition;

     if (filepath == NULL) {
        puts("[error] File path not provided");
        exit(EXIT_FAILURE);
     }

    if ((fp = fopen(filepath, READ)) == NULL) {
        puts("[error] File not found!");
        exit(EXIT_FAILURE);
    }

     puts("==================================READ FILE==================================");
    
    while (fgets(buff, BUFF_SIZE, fp) != NULL) {
        printf("    %s", buff);
    }

    rewind(fp);

     printf("\n==================================Analyzing==================================\n");
   
    while ((num_retrieved = fscanf(fp, "%d", &num)) != EOF) {
        if ((is_even_number(num)) == 1) {
            num_definition = ODD;
        } else {
            num_definition = EVEN;
        }

        printf("num: %d is %s ", num, num_definition);

        if ((is_prime(num)) == 1) {
            printf("and %s\n", PRIME);
        } else {
            printf("\n");
        }
    }

    if (fclose(fp) != 0) {
        fprintf(stderr, "[error] closing file");
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}


int main(void) {
    /* Read inputs from file and return whether is odd or even */
    int result;
    int number;
    const char filepath[sizeof(FILE_PATH)] = FILE_PATH;

    printf("Even/Odd check: Enter number: \n");
    scanf("%d", &number);

    result = is_even_number(number);
    printf("The number %d is [%d] (0 is even, 1 is odd)\n", number, result);

    /* read line from file: */
    even_odd_or_prime(filepath);


    return(EXIT_SUCCESS);
}
