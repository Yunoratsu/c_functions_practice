#include <stddef.h>
#include "strlen.h"

size_t Strlen(const char *s) {
    size_t len = 0;
    while (*s++) len++;
    return len;
}
