#include <stdio.h>
#include <stdlib.h>

/*
* Takes a number and  returns it multiplied by two. Uses only stack.
*
* @param input [double]
* @return [Double]
*/
double mutiplyByTwo (double input) {
    /* Stack variables: */
    double twice = input * 2.0;

    return twice;
    /* Pop off the stack */
}

/*
* Takes a number and  returns it multiplied by two. Uses only stack.
*
* @param input [double*]
* @return [pointer]
*/
/* double *myltiplyByTwoOnHeap (double *input) {
    double *twice = malloc(sizeof(double));
    *twice = *input * 2.0;
    
    return twice;
} */

int main(int argc, char *argv[]) { 
    /* Stack variables: */

    int age = 30;
    double salary;
    double myList[3] = {1.2, 2.3, 3.4};

    /* Heap variables: */
    /*
     *   int *age = malloc(sizeof(int));
     *   double *salary = malloc(sizeof(double));
     *   double *myList = malloc(3 * sizeof(double));
     * 
     *   age = 30;
     *   myList[0] = 1.2;
     *   myList[1] = 2.3;
     *   myList[3] = 3.4;
     */

    printf("Please enter you salary: ");
    
    /* 
    * %lf => long precision floating-point value (double)
    * %f => single precision floating-point value (float)
    * %i => (interger) 
    */
    scanf("%lf", &salary);

    printf("Double your salary is %.3f\n", mutiplyByTwo(salary));


    /* double *twiceSalary = myltiplyByTwoOnHeap(salary); */

    /* printf("Double your salary with heap is %.3f\n", twiceSalary); */

    /*    
     *   free(age);
     *   free(myList);
     *   free(salary);
     *   free(twiceSalary);
    */

    return 0;
}
