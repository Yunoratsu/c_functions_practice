#include <stdio.h>
#include "strlen.h"

#define SIZE 40

char    *strcat(char *dest, const char *src) {
    size_t dest_len = Strlen(dest);
    size_t i;

    for (i = 0; i < dest_len; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}


int     main(void) {
    char s1[SIZE] = "Hello";
    strcat(s1, ", MagMa! MAMA GUCI THAT SHIT IS BROKKKKKKKKKE");

    printf("String: %s\n", s1);

    return 0;
}
