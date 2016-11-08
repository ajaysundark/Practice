/* a simple stack implementation */
#include "stack.h"

#ifdef LL
int create_stack(element_t **stackptr, int init_size) {
    return 0;
}

int push (element_t **top, int data) {
    element_t *new_node = (element_t *) malloc (sizeof (element_t));
    if(!new_node) return -1;

    new_node->data = data;
    new_node->next = *top;

    *top = new_node;
    // printf("top now <data %d , new top  %p , old top %p>\n", new_node->data, (void *)new_node->next, (void*) *top);
    return 0;
}

int pop (element_t **top, int *data) {
    if(*top == NULL) return -1; //stack is empty

    element_t *deleteme = *top;
    *data = (*top)->data;
    *top = (*top)->next;
    free(deleteme);
    return 0;
}

int delete_stack(element_t **top) {
    if(*top == NULL) return -1; //empty stack

    while(*top) {
        element_t *next = (*top)->next;
        free(*top);
        *top = next;
    }

    top = NULL;
    return 0;
}

void count_stack(element_t *top) {
    int count = 0;
    while(top) {
        ++count;
        top = top->next;
    }
    printf("stack has %d elements\n", count);
}

void print_stack(element_t *top) {
    if(!top) printf("stack empty");
    while(top) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
#endif //LL

#ifdef DYNARR

#endif //DYNARR

int
main (int argc, char **argv) {
    element_t *stackptr = NULL;

#ifdef LL
    printf("Linked list implementation is defined.\n");
#endif
#ifdef DYNARR
    printf("Dynamic array implementation is defined.\n");
#endif

    create_stack (&stackptr, 10);
    push(&stackptr, 10);
    push(&stackptr, 1);
    push(&stackptr, 20);
    push(&stackptr, 3);

    count_stack(stackptr);
    print_stack(stackptr);

    int val;
    if(pop(&stackptr, &val)==0)
        printf("popped %d from stack, ", val);
    print_stack(stackptr);
    if(pop(&stackptr, &val)==0)
        printf("popped %d from stack, ", val);
    print_stack(stackptr);
    printf("delete stack now..\n");
    delete_stack(&stackptr);
    count_stack(stackptr);
    return 0;
}
