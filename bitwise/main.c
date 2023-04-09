#include <stdio.h>

int main(void) {
    /* bitwise operation: */
   
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;

    w3 = w1 & w2;

    /* Manial AND: if 1 and 1 => 1    */
    /* if 0 and 1 => 0                */
    /* 25 in binary: 0000000000011001 */
    /* 77 in binary: 0000000001001101 */
    /* ------------------------------ */
    /*  9            0000000000001001 */

    printf("& %d\n", w3);

    short int w4 = 147;
    short int w5 = 61;
    short int w6 = 0;

    /* Manial OR: if there is 1 in either => 1 */
    /* 147 in binary: 10010011        */
    /* 61 in binary:  00111101        */
    /* ------------------------------ */
    /* 191            10111111        */
 
     w6 = w4 | w5;


    printf("| %d\n", w6);

    short int w7 = 147;
    short int w8 = 61;
    short int w9 = 0;

    /* Manial XOR: if there is 1 in one but not both => 1 */
    /* 147 in binary: 10010011        */
    /* 61 in binary:  00111101        */
    /* ------------------------------ */
    /* 174            10101110        */
 
     w9 = w7 ^ w8;


    printf("^ %d\n", w9);

    /* real code example */
    /* short int temp = 0; */
    short int n1 = 10;
    short int n2 = 12;

    /* swap */
    /*  temp =  n1;
        n1 = n2;
        n2 = temp; */

    /* do not need temp variable */
    n2 ^= n1;
    n1 ^= n2;

    printf("n %d\n", n1);

    signed int s1 = 154;
    signed int result = 0;

    result = ~s1;

    /* Comliment: flip the bits       */
    /* 154 in binary: 10011010        */
    /* ------------------------------ */
    /* 174            01100101        */
    /* in twos compilent eq -155:     */
    /* 155 in binary  10011011 +1     */

    printf("~ result: %d\n", result);

    return 0;
}