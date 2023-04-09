#include <stdio.h>

long long convertDecimalToBinary(int n){
   long long binaryNumber = 0;
   int remainder, i=1;

   while(n != 0) {
     remainder = n%2;
     n = n / 2;
     binaryNumber += remainder * i;
     i = i * 10;
   }

   return binaryNumber;

}

int main(void) {
    int a;
    int b;
    long long aBinary;
    long long bBinary;
    long long negationA;
    long long negationB;
    long long resultAnd;
    long long resultOR;
    long long resultXOR;
    long long shiftA;  
 

    printf("Please enter two integers numbers: \n");
    printf("a: ");
    scanf("%i", &a);
    printf("b: ");
    scanf("%i", &b);

    printf("\n===========================================\n");

    aBinary = convertDecimalToBinary(a);
    bBinary = convertDecimalToBinary(b);
    printf("  binary (a):                [%lld]\n", aBinary);
    printf("  binary (b):                [%lld]\n", bBinary);

    negationA = ~aBinary;
    negationB = ~bBinary;
    printf("  ~ (a)                      [%lld]\n", negationA);
    printf("  ~ (b)                      [%lld]\n", negationB);

    resultAnd = aBinary & bBinary;
    printf("  & (a, b)                   [%lld]\n", resultAnd);

    resultOR = aBinary | bBinary;
    printf("  | (a, b)                   [%lld]\n", resultOR);

    resultXOR = aBinary ^ bBinary;
    printf("  ^ (a, b)                   [%lld]\n", resultXOR);

    shiftA = aBinary << 2;
    printf("  <<(a, 2)                   [%lld]\n", shiftA);

    printf("\n===========================================\n");


    return 0;
}