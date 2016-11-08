#include "list.h"

static node_t *_head = NULL;
static unsigned int nnodes = 0;

/* TODO enhancement : if prev!=NULL use prev as starting point for find */
int find_previous_ptr(node_t **prev, int current_data) {
	node_t *runner = _head;
	int err = LL_NOT_FOUND;
	if (runner==NULL) { //empty list
		return LL_EMPTY; //insert at front
	}

	// atleast one element present 
	(*prev) = NULL;
	if (runner->data > current_data)
	{ return LL_NOT_FOUND; }

	if (runner->data == current_data)
	{ return LL_SUCCESS; }

	while (runner->next) {
		if (runner->next->data > current_data) {
			break;
		}

		if(runner->next->data == current_data) {
			err = LL_SUCCESS;
		}
		runner = runner->next;
	}

	(*prev) = runner;
	return err;
}

int insert_data (int data) {
	node_t *addendum = (node_t *) calloc(1, sizeof(node_t));
	node_t *previous;
	int err = LL_SUCCESS;

	if(!addendum) {
		return LL_MEM_ERR;
	}

	addendum->data = data;
	err = find_previous_ptr(&previous, addendum->data);
	if(err==LL_EMPTY) {
		// printf("Debug: for data %d find_prev_ptr returned as EMPTY\n", data);
		_head = addendum;
		err = LL_SUCCESS;
	} else if (err == LL_NOT_FOUND || err == LL_SUCCESS) {
		// printf("Debug: for data %d, find_prev_ptr returned %s error code %d",data, (previous==NULL) ? "NULL":"", err);
		if (previous == NULL)  {
		//	printf("\n");
			addendum->next = _head;
			_head = addendum;

		}
		else {
		//	printf(" with previous ptr to %d\n", previous->data);
			addendum->next = previous->next;
			previous->next = addendum;
		}
		err = LL_SUCCESS;
	} else fprintf(stderr, "insert_data failed with %d", err);

	// printf("Debug: inside insert for %d : list now : ", data);
	// print_list();

	nnodes += (err==LL_SUCCESS);
	return err;
}

node_t *find (int data) {
	node_t *runner = _head;
	while(runner && runner->data != data) {
		if (runner->data > data) runner = NULL;
		else runner = runner->next;
	}
	
	return runner;
}

void print_list() {
	node_t *runner = _head;
	while(runner) {
		printf("%d ", runner->data);
		runner = runner->next;
	}
	printf("\n");
}

int delete_data (int data) {
	node_t *prev = NULL;
	node_t *deleteme = NULL;
	int err, count=0;
	while ( (err=find_previous_ptr(&prev, data)) == LL_SUCCESS ) {
	// if ( (err = find_previous_ptr(&prev, data)) ==LL_SUCCESS ) {
		if (prev == NULL) {
			// first element at LL
			deleteme = _head;
			_head = _head->next;
			free(deleteme);
		}
		else {
			deleteme = prev->next;
			prev->next = prev->next->next;
			free(deleteme);
		}

		--nnodes;
		// till the find_previous_enhancement
		++count;
	}

	return count;
}


int get_nnodes() {
	return nnodes;
}

/* test */
/* int main(int argc, char const *argv[])
{
		
	return 0;
}*/
