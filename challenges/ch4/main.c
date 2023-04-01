#include <stdio.h>

#ifdef __STDC_NO_VLA__
  printf("VLA not supporterd");
  exit(1);
#endif

/*
* Function to create new array using VLA.
*
* @param arr [*int] pointer to pass the new array address.
* @param size [unsigned long, size_t]
* @return [void]
*/
void new_array(int *arr, size_t size) {
    int new_array[size];
    int i;
    
    for(i = 0; i < size; i++) {
        printf("Please enter array element [%i]: ", i);
        scanf("%i", &new_array[i]);
    }

    printf("Array created\n");
    arr = new_array;
}

int main(void) {
    size_t array_size = 0;
    int *array;
    int i;
    int sum = 0;

    printf("Please enter array size:");
    scanf("%zd", &array_size);
    
    /* creates and fills with elements new array */
    new_array(array, array_size);
    
    for(i = 0; i < array_size; i++) {
        sum += array[i];
    }

    printf("The sum of all elements is: %d", sum);
    return 0;
}