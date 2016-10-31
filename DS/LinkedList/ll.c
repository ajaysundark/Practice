#include "ll.h"

static size_t getsize(Datatype_t type) {
    switch(type)
    {
        case integer_t:
            return sizeof(int);
        case character_t:
            return sizeof(char);
        case float_t:
            return sizeof(float);
        case UNDEFINED:
        default:
            return 0;
    }
}

void free_list (node_t **head) {
    while (*head) {
        node_t *frunner = (*head)->next;
        free(*head);
        *head = frunner;
    }
    head = NULL;
}

void print_node (node_t *node) {
    if(!node) return;

    switch (node->type) {
        case integer_t:
            printf("%d ", *(int *)node->data);
            break;
        case character_t:
            printf("%c ", *(char *)node->data);
            break;
        case float_t:
            printf("%f ", *(float *)node->data);
            break;
    }
}

void insert_node (node_t **head, void *data, Datatype_t type) {
    node_t *new_node = (node_t *) malloc( sizeof(node_t) );
    if(!new_node) {
        fprintf(stderr, "malloc failed : %s\n", strerror(errno));
        exit(1);
    }

    new_node->type = type;
    new_node->data = malloc (getsize(type));
    memcpy(new_node->data, data, getsize(type));
    new_node->next = *head;

    *head = new_node;
}

void delete_node (node_t **head, node_t *deleteme) {
    node_t *runner = *head;
    node_t *prev = *head;
    if(!runner) return;

    /*if delete first element, update head*/
    if(runner->data == deleteme->data) { 
        *head = runner->next;
        free(runner);
        return;
    }
    runner = runner->next;

    while(runner) {
        if( runner->type == deleteme->type && (memcmp(runner->data,deleteme->data,getsize(deleteme->type))==0) ) {
            prev->next = runner->next;
            free(runner);
            return;
        }
        prev = runner;
        runner = runner->next;
    }
}

void delete_value (node_t **head, void *value, Datatype_t type) {
    node_t *temp = (node_t *) malloc ( sizeof(node_t) );
    temp->type = type;
    temp->data = value;
    delete_node(head, temp);
    free(temp);
}

node_t *find_value (node_t *head, void *value, Datatype_t type) {
    while (head) {
        switch(type) {
            case integer_t:
                if(*(int *)value == *(int *)head->data) return head;
                break;
            case character_t:
                if(*(char *)value == *(char *)head->data) return head;
                break;
            case float_t:
                if(*(float *)value == *(float *)head->data) return head;
                break;
        }
        head = head->next;
    }
    return (node_t *) NULL;
}

void append_lists (node_t *head1, node_t *head2) {
    if(head1) {
        node_t *runner = head1->next;
        while (runner) {
            //find the last element
            head1 = runner;
            runner = runner->next;
        }
        head1->next = head2;
    }
}

void print_list (node_t *head) {
    while(head) {
        print_node(head);
        head = head->next;
    }
}
