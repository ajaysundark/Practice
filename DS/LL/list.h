#ifndef LIST_H
/* sorted linked list */
#define LIST_H

#define LL_NOT_FOUND -4
#define LL_EMPTY -3
#define LL_MEM_ERR -2
#define LL_FAILURE -1
#define LL_SUCCESS 0

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node_t;

int insert_data(int data);
int delete_data (int data);
node_t *find (int data);
int get_nnodes();
void print_list();
#endif
