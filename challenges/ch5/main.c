#include <stdlib.h>
#include <malloc.h>
#include <time.h>

struct myArray {
    int arraySize;
    int array[];
};

int main(void) {
    int i;
    size_t size;
    /* declare empty struct with pointer */
    struct myArray *arrPointer = NULL; 
    /*  struct myArray arr1; */ 

    /* Random number init: */
    srand(time(NULL));

    printf("Please enter size for flexible array: ");
    scanf("%zd", &size);

    /* Dynamically allocating memory for the struct and flexible array. */
    arrPointer = malloc( sizeof( struct myArray ) + size * sizeof(int) );

    /*
    * arrPointer->arraySize = size;
    * arr1.arraySize = size;
    * printf("Test array size: %i", arr1.arraySize);
    */

   arrPointer->arraySize = size; 

   /* fill the array with dummy data and print it */
    for( i = 0; i < arrPointer->arraySize; i ++) {
        arrPointer->array[i] = rand();
        printf("element: %i \n", arrPointer->array[i]);
    }

    free(arrPointer);
    return 0;
}