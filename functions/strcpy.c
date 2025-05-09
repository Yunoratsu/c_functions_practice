#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#undef strcpy
/* disable internal stpcpy optimization, otherwise the __stpcpy might it generate a strcpy call. */
#undef __stpcpy

#ifndef STRCPY
# define STRCPY strcpy
#endif

/* Copy SRC to DEST. */
char *STRCPY (char *dest, const char *src) {
    __stpcpy(dest, src);
    return dest;
}

char    *strCpy(char *dest, const char *src) {
    const size_t length = strlen(src);

    memcpy(dest, src, length + 1);
    return dest;
}

char     *Strcpy(char *dest, const char *src) {
    const char *ptr = src;
    int i = 0;

    while (*ptr != '\0') {
        dest[i++] = *ptr;
        ptr++;
    }
    dest[i] = '\0';

    return dest;
}

//Any functions applied, what a masterpiece (or not haha)
// It basically assigns ( = ) each value in src to dest, the ; in while simply say do nothing...
// Once we copy the null terminator ('\0') the assignment results in 0 which is false -- loop ends...
//More elegant, compact and uses only pointers, no arrays...
char    *strcPy(char *dest, const char *src) {
    char *start = dest;

    while ((*dest++ = *src++))
        ;
    return start;
}

int     main(void) {
    char source[] = "Hello, magma!";
    char destination[50];

    strcPy(destination, source);

    printf("Copied string: %s\n", destination);
    
    return 0;
}

