#include <stdio.h>

int main(void) {
    /* integer in most system is represented by 32 bits. */
    /* int i = 1; */
    /* 0000 0000 0000 0000 0000 0000 0000 0001 */

    /* 0000 0000 0000 0000 0000 0000 0000 0011 */
    int i1 = 3;

    int result = 0;

    /* shift by one                            */
    /* 0000 0000 0000 0000 0000 0000 0000 0110 */
    result = i1 << 1;

    printf("shft left result: %d\n", result);

    /* 0000 0000 0000 0000 0000 0000 0000 1100 */
    i1 = 12;
    /* 0000 0000 0000 0000 0000 0000 0000 0110 */
    result = i1 >> 1;

    printf("shift right result: %d\n", result);

    return 0;
}