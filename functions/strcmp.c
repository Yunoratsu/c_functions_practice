#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "strlen.h"
#include "strncpy.h"
/* Logic:
 * Compare starting from index 0
 * if they are equal and diff than '\0' (NULL)
 * increment
 * otherwise, return the diff between s1 and s2
 */

// This Strcmp is the same code as strCmp but less optimized and probably not so """error proof""" as the 
// second one (strCmp)...
int     Strcmp(const char *s1, const char *s2) {
    const char *c1 = s1;
    const char *c2 = s2;
    int u1, u2;
    
    do {
        u1 = *c1++;
        u2 = *c2++;
        if (u1 == '\0')
            return u1 - u2;
        
    } 
    while(u1 == u2);

    return u1 - u2;
}

int stRcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && (*s1 == *s2)) {
        s1++; // We only use * in the front if we want to fetch a value and store it, i.e: char c = *s1++;
              // <- char c = *s1; s1++; / if we're just trying to advance the pointer we write like that.
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int     strCmp(const char *p1, const char *p2)
    //strCmp(p1, p2) {
    //const char *p1; -> a technique we can do :)
    //const char *p2;
{
    register const unsigned char *s1 = (const unsigned char *) p1;
    register const unsigned char *s2 = (const unsigned char *) p2;
    unsigned c1, c2;

    do 
      {
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;
        if (c1 == '\0')
            return c1 - c2;
      } 
    while (c1 == c2);

    return c1 - c2;
}

// Mine:
int     compare_string(const char *s1, const char *s2) {
    while (*s1 == *s2 && (*s1 != '\0')) {
        s1++;
        s2++;
    }

    if (*s1 == *s2) {
        return 0;
    } else if (*s1 > *s2) {
        return 1;
    } else {
        return -1;
    }
}

int     compare_wlimit(const char *s1, const char *s2, size_t limit) {
    if (limit > strlen(s1) || limit > strlen(s2) || limit <= 0) {
        fprintf(stderr, "The characters number is not in the string range.\n");
        exit(1);
    }
    for (int i = 0; i < limit; i++) {
        if ((s1[i] == s2[i]) && s1[i] != '\0') {
            i++;
        }
        return *(const unsigned char *)s1 - *(const unsigned char *)s2;
    }
}

int     compare_casei(const char *s1, const char *s2) {
    
    while ((tolower(*s1) == tolower(*s2)) && (*s1 != '\0')) {
        s1++;
        s2++;
    }

    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);

}

int main(void) {
    char *a = "Massachussets";
    // Error trying to copy string from a to b...
    size_t size = Strlen(a) + 1;
    char *b = malloc(size); //even with malloc(size), strlen() still dont work... with or without (char *)
    char *c = "maSSachussets";
    strcpy(b, a);
    b[size] = '\0';

    if(compare_casei(a, c) == 0) {
        printf("\033[33m""Same string.\n""\033[0m");
    } else {
        printf("\033[31m""Not the same string.\n""\033[0m");
    }

    free(b);
    return 0;
}
