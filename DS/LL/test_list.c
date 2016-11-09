#include "list.h"

int main () {
	int i = 4;
	int err = 0;
	printf("Below are being inserted into the list :\n");
	for (; i>=0; --i) {
		err = insert_data(i);
		if(err==LL_SUCCESS)
			printf("%d ", i);
		else {
			printf("\n Error occurred %d\n", err);
			break;
		}
	}

	printf("\nNumber of nodes at list %u\n\n", get_nnodes());	
	printf("Below is the insertion order at the list 0..9 :\n");
	print_list();

	printf("\nLet us try to find 4: \n");
	node_t *mynode = find(4);
	if(mynode) {
		printf("As retrieved from LL,\n\tdata : %d\n", mynode->data);
	}
	printf("insert another 3..\n");
	err = insert_data(3);
	print_list();
	printf("Deleting 2..\n");
	delete_data(2);
	print_list(); 
	printf("Deleting 3..\n");
	delete_data(3);
	print_list(); 
	return 0;
}
