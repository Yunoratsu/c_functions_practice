#include <stdlib.h>
#include <stdio.h>

#include "strlen.h"

#define SIZE 30

#undef strncat
char    *strncat(char *dest, const char *src, size_t n) {
    size_t dest_size = Strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_size + i] = src[i];
    }
    dest[dest_size + i] = '\0';

    return dest;
}



int     main(void) {
    char s1[] = "Massak";
    char s2[] = ", malawui!";
    strncat(s1, s2, 10);

    printf("%s\n", s1);

    return 0;
}
