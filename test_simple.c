#include <stdio.h>

int main(int argc, char const *argv[])
{
	int var;
	printf("var without init : %d\n", var);
	var = printf("This is just a test print\n");
	if(! var)
		printf("My assumption that !var is 0 is wrong\n");
	else
		printf("Yaay! It's true.\nvar = %d and !var = %d\n", var, !var);

	// !var is indeed 0
	return 0;
}
