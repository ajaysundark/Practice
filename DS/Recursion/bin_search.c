#include "bin_search.h"

int bsearch(int *array, int left, int right, int target) {
	unsigned int center = left + (right - left)/2;
	if ( (left > right) || (left==right && target!= array[left]) ) 
	{
		fprintf(stdout, "\nTarget %d not found!", target);
		return (TARGET_NOT_FOUND);
	}

	if (array[center] == target)
	{
		return center;
	} 
	else if (array[center] < target)
	{
		bsearch(array, center+1, right, target);
	} 
	else
	{
		bsearch(array, left, center-1, target);
	} 
}

int bsearch_iter (int *array, int left, int right, int target) {

	while (1) {

		unsigned int center = left + (right - left)/2;

		if ( (left > right) || ( (left==right) && (target!= array[left]) ) )
		{
			fprintf(stdout, "\nTarget %d not found!", target);
			return (TARGET_NOT_FOUND);
		}

		if (array[center] == target)
		{
			return center;
		}
		else if (array[center] < target)
		{
			left = center+1;
		}
		else {
			right = center-1;
		}
	}
}

int int_cmp(const void *a, const void *b) {
	int inta = *(int *)a; 
	int intb = *(int *)b;
	return (inta-intb);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,33,41,42,51,43,11,23,64,123, 0, -4, -19, 79} ;
	int len = sizeof(arr)/sizeof(int);

	printf("%10s", "Index : ");
	for (int i = 0; i < len; ++i)
	{
		printf("%3d ", i);
	}

	printf("\n%10s", "Values : ");
	for (int i = 0; i < len; ++i)
	{
		printf("%3d ", arr[i]);
	}

	// Binary search will work only on sorted array
	qsort(arr, len, sizeof(int), int_cmp);
	printf("\n%10s", "Sorted : ");
	for (int i = 0; i < len; ++i)
	{
		printf("%3d ", arr[i]);
	}	

	int foundat;
	foundat = bsearch(arr, 0, len-1, 33);
	if(foundat>0) printf("\n\nLook what I found: %d at %u", 33, foundat);

	foundat = bsearch(arr, 0, len-1, 1);
	if(foundat>0) printf("\nLook what I found: %d at %u", 1, foundat);

	foundat = bsearch(arr, 0, len-1, 0);
	if(foundat>0) printf("\nLook what I found: %d at %u", 0, foundat);

	foundat = bsearch(arr, 0, len-1, -6);
	if(foundat>0) printf("\nLook what I found: %d at %u", -6, foundat);

	foundat = bsearch(arr, 0, len-1, 51);
	if(foundat>0) printf("\nLook what I found: %d at %u", 51, foundat);

	return 0;
}
