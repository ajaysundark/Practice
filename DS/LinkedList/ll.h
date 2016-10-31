#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef enum Datatype {
    integer_t = 1,
    character_t,
    float_t,
    UNDEFINED
} Datatype_t;

typedef struct node {
    void *data;
    Datatype_t type;
    struct node *next;
} node_t;

void insert_node (node_t **head_ref, void *data, Datatype_t type);
void delete_node (node_t **head_ref, node_t *deleteme);
void delete_value (node_t **head_ref, void *value, Datatype_t type);
void append_lists (node_t *head_ref1, node_t *head_ref2);
void free_list (node_t **head);
void print_list ( node_t *head_ref);
void print_node ( node_t *node);
#endif
