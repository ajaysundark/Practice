#ifndef BIN_SEARCH
#define BIN_SEARCH
#include <stdio.h>
#include <stdlib.h>

#define TARGET_NOT_FOUND -1

/*I expect arr to be a sorted array */
int bsearch(int *arr, int left, int right, int target);
#endif