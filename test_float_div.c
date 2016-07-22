#include <stdio.h>
int main(int argc, char const *argv[])
{
	float t=1.0/3.0;
	printf("%f\n", t);
	if (t*3 == 1.0)
		printf("yes\n");
	else
		printf("no %f is the value\n", t*3);
	return 0;
}

/* output

$ ./test_float_div.exe
0.333333
no 1.000000 is the value

why, no here??
*/