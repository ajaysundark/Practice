#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/* default is Linked list based implementation*/
#define LL 

/* Have either LinkedList or Dynamic Array flag set, not both 
 * to use DYNARR compile with -DDYNARR flag */

#ifdef DYNARR
#undef LL
#endif

typedef struct element {
    int data;
    struct element *next;
} element_t;

int push (element_t **top, int data);
int pop (element_t **top, int *data);
int create_stack (element_t **top, int init_size); // valid for DYNARR based implementation
int delete_stack (element_t **top);

#endif
