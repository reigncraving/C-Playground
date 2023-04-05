#include <stdio.h>
#include <malloc.h>

struct s {
    int arraySize;
    /* flexible array */
    int array[];
};


int main(void) {
    int desiredSize = 5;
    /* structure pointer => structure named s */
    struct s *ptr; 

    /* 
    *
    * allocate size of one struct size for all members and 
    * desiredSize is allocation for the flexible array member
    * how many elements will that array hold.
    */
    ptr = malloc( sizeof( struct s ) + desiredSize * sizeof ( int ) );

    free(ptr);
    
    return 0;
}
