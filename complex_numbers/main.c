#include <stdio.h>
#include <complex.h>

#ifdef __STDC_NO_COMPLEX__
  printf("Complex numbers are supported");
  exit(1);
#endif

int main(void) {
    /* I is defined in Header*/
    double complex cx = 1.0 + 3.0*I;
    double complex cy = 1.0 - 4.0*I;

    printf("working with complex numbers");
    printf("Starting Values: cx = %.2f%+.2fi cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

    double complex sum = cx + cy;
    printf("The sum of cx + cy is: %.2f%+.2fi\n", creal(sum), cimag(sum));

    char x =8;
    printf("sizeof [x] = %d", sizeof(x));
    return 0;   
}
