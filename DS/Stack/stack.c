/* a simple stack implementation */
#include "stack.h"

int push (element_t **top, element_t *new_node) {
    return 0;
}

element_t *pop (element_t **top) {
    return NULL;
}

int
main (int argc, char **argv) {
#ifdef LL
    printf("Linked list implementation is defined.\n");
#endif
#ifdef DYNARR
    printf("Dynamic array implementation is defined.\n");
#endif
    return 0;
}
