#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[255];
    int ch = '\0';
    char *p = NULL;

    if (fgets(buf, sizeof(buf), stdin)) {
        /* strchr looks to see if '\n' is found */
        p = strchr(buf, '\n');
        if(p) {
            *p = '\0';
        } else {
            /* read untill end of line, end of file and there are no errors. */
            while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin) );
        }
    }

    printf("buffer: %s\n", buf);

    return 0;
}
