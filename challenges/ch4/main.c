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
void sum_new_array(size_t size) {
    int new_array[size];
    int j;
    int i;
    int sum = 0;
    
    for(j = 0; j < size; j++) {
        printf("Please enter array element [%i]: ", j);
        scanf("%i", &new_array[j]);
        printf("Entered value: %i\n", new_array[j]);
    }

    printf("Array created\n");

        for(i = 0; i < size; i++) {
        sum += new_array[i];
    }
    

    printf("The sum of all elements is: %i", sum);
}

int main(void) {
    size_t array_size = 0;

    printf("Please enter array size:");
    scanf("%zd", &array_size);
    
    /* creates and fills with elements new array, prints sum */
    sum_new_array(array_size);
    
    return 0;
}