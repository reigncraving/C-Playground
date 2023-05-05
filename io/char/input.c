#include <stdio.h>
#include <ctype.h>

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

    FILE *fp = fopen("./io/char/test_file.txt", "r");
    char c;

    if (fp == NULL ) {
        printf("could not open the file.");
        return 1;
    }

    printf("Reading file...");

    while (1) {
        c = fgetc(fp);
        if (c == EOF) {
            break;
        }
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);

    /* fgetc */

    printf("Enter as much spaces as wanted, before a char to be returned.\n");
    /* function to ignores spaces from io stream */
    char chnew = 0;

    /* semicolon is used to read as long as there is space.*/
    while (isspace(chnew = (char)getchar()));
        /* put back the non spoace char. */
        ungetc(chnew, stdin);

    printf("non space char: %c\n", chnew);

    return 0;
}