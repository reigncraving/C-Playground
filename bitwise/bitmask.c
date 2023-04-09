#include <stdio.h>

int main(void) {
    /* 0000 1111*/
    int flags = 15;
    /* 1011 0110*/
    int mask = 182; 

    /* 1011 1111*/
    flags = flags | mask; 
    if ((flags & mask) == mask) {
        printf ("checking value: True\n");
    }

    printf("flags | mask %d\n", flags);

    flags = 15;
    /* 0000 1001 */
    flags = flags & ~(mask); 

    printf("flags &~ mask %d\n", flags);


    flags = 15;
    /* 1011 1001 */
    flags = flags ^ mask; 

    printf("flags ^ mask %d\n", flags);
    return 0;
}