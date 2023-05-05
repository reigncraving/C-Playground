#include <stdio.h>

int main(void) {
    /* putchar */
    /* __STDIO_INLINE int
        putchar (int __c)
        {
        return putc (__c, stdout);
        }
    */
    char string[] = "Hello, there!\n";
    int i = 0;

    while( string[i] != '\0') {
        if (string[i] != '\n') {
            putchar(string[i]);
        }
        i++;
    }

    putc('\n', stdout);

    FILE *fp = NULL;
    char ch = '\0';

    /* open file reads it's chars and replace them with themselves */
    if ((fp = fopen("./io/char/test_file.txt", "rw"))) {
        ch = getc(fp);

        while(ch != EOF) {
            putc(ch, fp);
            ch = getc(fp);
        }

        printf("Last appended character: %c", ch);
        fclose(fp);
        putc('\n', stdout);
    }


    /* fputc(int character, FILE *stream);*/

    FILE *filepointer = NULL;
    char b = '\0';

    filepointer = fopen("./io/char/output.txt", "w");

    if (filepointer != NULL) {
        for (b = 'A'; b <= 'Z'; b++) {
            fputc(b, filepointer);
        }
        fclose(filepointer);
    }

    return 0;
}
