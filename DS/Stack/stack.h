#ifndef STACK_H
#define STACK_H

#include <stdio.h>

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

int push (element_t **top, element_t *new_node);
element_t *pop (element_t **top);
int create_stack (int init_size); // valid for DYNARR based implementation
int delete_stack ();

#endif
