#include <stdio.h>

#ifdef __STDC_NO_VLA__
    printf("Variable length arrays are not supporterd\n")
#endif

void array(int size) {
    char new_array[size];
    int idx = 0;


    while(idx < size) {
        /* pushes next index of alphabet char */
        new_array[idx] = 'A' + idx;
        printf("=>%c\n", new_array[idx]);
        idx++;
    }

}

int main(void) {

    /* size_t is type return from sezof operator*/
    size_t size = 0;

    printf("Please enter size of the array:");
    scanf("%zd", &size);

    /* c89 do not support this */
    /* float values[size]; */

    array(size);

    return 0;
}