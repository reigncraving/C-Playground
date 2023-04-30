#include <stdio.h>

/* 
* Functions getting file pointer, and returning int.
* Characters are represented by integers in ASCII table.
*
* int getc(FILE *stream)
*/

int main(void) {
    /* init to null character: 0 terminated */
    char ch = '\0';
    /* FILE *file_pointer; */

    /* open file in rw mode, you can read from stdin as it is a file as */
   /*  if (file_pointer = fopen("filename.ext", "rw")) { */
        /* read the first character from file: */
  /*       ch = getc(file_pointer);

        while (ch != EOF) {
            ch = getc(file_pointer);
        }
        fclose(file_pointer);
    }
 */
    /* read form console */
    puts("enter char:");
    ch = getc(stdin);
    printf("read character %c\n", ch);
    /* getc reads from every input, while getchar only from console.*/

    puts("enter char:");
    ch = getc(stdin);
    printf("read: %c\n", getchar());

    /* with integer with while loop regular implementation: */
    /*
    * Use int with EOF, not char.
    * int ch = 0;
    * while((ch = getchar()) != EOF) 
    * 
    */


   /* read a file: int fgetc(FILE *fp) */

   /* check if file exist: if (fp == NULL) { return 1; }*/

    return 0;
}