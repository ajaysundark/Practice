#include "ll.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int
main (int argc, char **argv) {
    int i = 0, n;
    int iarray[] = {1,3,4,5};
    float farray[] = {2.1,2.2,2.3,2.4};
    char charray[] = {'a','b','c'};

    node_t *headptr = NULL;
    node_t *headptr2 = NULL;

    n = NELEMS(iarray);
    for(;i<n;++i) {
       insert_node(&headptr, iarray+i, integer_t); 
    }

    printf("created integer array with linked list.\n");
    print_list(headptr);
    printf("\n");

    free_list (&headptr);

    n = NELEMS (farray);
    for(i=0;i<n;++i) {
       insert_node(&headptr, farray+i, float_t); 
    }

    printf("created float array with linked list.\n");
    print_list(headptr);
    printf("\n");

    n = NELEMS (charray);
    for(i=0;i<n;++i) {
       insert_node(&headptr2, charray+i, character_t); 
    }

    printf("created char array with linked list.\n");
    print_list(headptr2);
    printf("\n");

    append_lists(headptr, headptr2);
    printf("merged the linked lists.\n");
    printf("the list now is \n");
    print_list(headptr);
    printf("\n");

    char test = 'a';

    delete_value (&headptr, &test, character_t);
    printf("\ndeleted %c, list now is ", test);
    print_list(headptr);
    printf("\n");

    free_list (&headptr);
    if (headptr2) {
        printf("\n but why headptr2 is still alive?\n");
        print_list(headptr2);
    }
    return 0;
}
