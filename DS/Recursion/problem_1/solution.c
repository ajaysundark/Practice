#include <stdio.h>

int find_arr_index_match_pair(int *arr, int lower, int upper) {
	int center = lower + (upper-lower)/2;
	if ( (lower == upper) && (arr[center]!=center) ) {
		return -1;
	}

	int X = arr[center]-center;
	if (X == 0)
	{
		return center;
	}
	else if (X < 0)
	{
		find_arr_index_match_pair(arr, center+1, upper);
	}
	else {
		find_arr_index_match_pair(arr, lower, center-1);
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {-3,-1,0,3,5,7};
	int len = sizeof(array)/sizeof(int);

	/* I assume there is only one element that matches the criteria! */
	int ans = find_arr_index_match_pair(array, 0, len);
	if (ans > 0)
	{
		printf("I found the X[i] == i, at %d\n", ans);
	}
	return 0;
}