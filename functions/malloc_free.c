#include <stdbool.h> // true or false for memory actual state
#include <stdlib.h>
#include <stddef.h> //for size_t and NULL
#include <unistd.h> //for sbrk() and brk()
#include <stdio.h>

#define SIGNATURE 0x1337

/************************************************
 * Malloc And Free - Yunoratsu, version 1     ***
 * Attempt: 1, date: 06/05/2025 Time: 18:51:00 **
 * Objective: make a working malloc and free,  **
 * Purpose: study memory in C                 ***
 ************************************************/

/************************************************
 * This can't even be called code, it was made **
 * with help of ChatGPT (im not that good in  ***
 * memory handling rn, but i will be). So pls ***
 * don't you dare to call something unworthy  ***
 * like this a "code project"!                 **
************************************************/

/* The functions we will probably use is memset() and sbrk() 
 * void *sbrk(intptr_t increment); && int brk(void *addr)
 * ============================================================
 * brk sets the program break to the location specified by addr;
 * sbrk increments the size of the program break by increment;;
 * ============================================================
 * Increasing the program break has the effect of allocating memory for the process,
 * decreasing the break deallocates memory
 * (Top) Stack -> Unallocated memory <- (Bottom) Heap 
 */

/************************************************
 * Our fckg steps:
 * We need a way to actually control memory blocks,
 * (see if there is a free one) if there is no free
 * memory block, we need to increment the program break
 * (sbrk) or in other words manipulate the heap.
 * We need a way to handle alignment (data types)
 * We need to check if malloc fails, and last but not
 * least, how we are going to check for memory corruption?
 ************************************************/

typedef struct mmemory {
    size_t size_of_block;
    bool used; //or int free
    struct mmemory *next;
    int signature;
} mmemory;

mmemory *head = NULL;

 /* Arrow (->) is used to access members of a struct/union;
 *  Dot (.) is used to set values in a struct/union variable.
 */

#undef malloc

void     *malloc(size_t size) {
    size_t total = sizeof(mmemory) + size;
    if (head == NULL) {
        head = (mmemory *)sbrk(total);
        if (head == (void *)-1) return NULL; // sbrk failed...
        head->signature = SIGNATURE;
        head->size_of_block = total;
        head->next = NULL;
        head->used = true;
        return (void *) (head + 1);
    }

    // Searching for a free block
    mmemory * current = head;
    
    while (current != NULL) {
        if (!current->used && current->size_of_block >= size) {
            current->used = true;
            return (void *) (current + 1);
        }
        if (current->next == NULL) break;
        current = current->next;
    }

    mmemory *new_block = (mmemory *)sbrk(total);
    if (new_block == (void *)-1) return NULL; //sbrk failed...
    new_block->size_of_block = size;
    new_block->signature = SIGNATURE;
    new_block->next = NULL;
    new_block->used = true;
    current->next = new_block;

    return (void *) (new_block + 1);
    
}

void    free(void *ptr) {
    if (ptr == NULL) return;
    mmemory *block = (mmemory *)ptr - 1;
    
    if (block->used && (block->signature == SIGNATURE)) {
        // freeing it
        block->used = false;
    } else {
        fprintf(stderr, "Double free or memory corruption\n");
        exit(1);
    }
}

int     main(void) {
    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));
    *x = 42;
    *y = 21;
    printf("x = %d, y = %d\n", *x, *y);

    free(x);
    free(y);
}

/* To next: real mallocs coalesce memory (merge adjacent free blocks). */
