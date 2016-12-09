#include <stdio.h>

struct test_data
{
	int var;
	unsigned char *name;
};

int foo (struct test_data t)
{
	#define fmt "%d is the value at test_data.var\n"
	printf("Im inside foo!\n");
	printf(fmt , t.var);
	#undef fmt
	return 0;
}

int main(int argc, char const *argv[])
{
	struct test_data dat1;
	dat1.var = 123;
	foo(dat1);
	return 0;
}