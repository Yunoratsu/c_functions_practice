#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strlen.h"
#include "strncpy.h"

#undef strncpy

#ifndef STRNCPY
 #define STRNCPY strncpy
#endif

char    *STRNCPY(char *s1, const char *s2, size_t n) {
    size_t size = strlen(s2);
    
    memcpy(s1, s2, size);

    if (size != n)
        memset(s1 + size, '\0', n - size);
    
    memcpy(s1, s2, size);
    s1[size] = '\0';
    return s1;
}

char    *Strncpy(char *dest, const char *src, size_t n) {
    size_t size = strlen(src);
    if (size != n) {
        memset(dest + size, '\0', n - size);
    }
    memcpy(dest, src, size);
    dest[size] = '\0';
}

char    *strNcpy(char *dest, const char *src, size_t n) {
    size_t size = strlen(src);
    char *start = dest;

    if (size != n) {
        memset(dest + size, '\0', n - size);
    }
    while ((*dest++ = *src++)) {
        ;
    }
    return start;
}

char    *strnCpy(char *dest, const char *src, size_t n) {
    size_t size = Strlen(src);
    int i = 0;
    const char *ptr = src;
    
    if (size != n) {
        exit(1);
    }

    while (*ptr != '\0') {
        dest[i++] = *ptr;
        ptr++;
    }
    dest[i] = '\0';

    return dest;
}


/*
int main(void) {
    char source[] = "Hello, obsidian!";
    char destination[100];
    size_t length = strlen(source);

    Strncpy(destination, source, length);

    printf("Our string is: %s\n", destination);

    return 0;
}*/
