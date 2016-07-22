#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char text[5] = {0};
	printf("%d\n", text[0]);
	if(!text[0] && !text[1])
	{
		printf("try 1. before initializing..\n");
		printf("Text is empty\n");
	}
	strcpy(text, "hi!"); //Note: strcpy doesn't check for size of buffer. so, trying to copy a string of length more than originally allocated (here, 5)
			     //                                                        could result in undefined behavior (may work or crash) to avoid risk use strncpy from GLibc
	printf("try 2. after initializing..\n");
	if(text[0])
	{
		printf("%c\n", text[0]); 
		printf("%s\n", text);
	}
	else
	{
		printf("Text is empty\n");
	}
	printf("Printing text anyway\n");
	printf("%s\n",text);
	return 0;
}
