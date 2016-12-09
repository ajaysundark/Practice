#include <stdio.h>
#include <string.h>
void my_test_log(const char *prefix, const char *string);
#define LOG(X, STR)\
{\
	my_test_log ("Test :" X, STR);\
}


int main(int argc, char const *argv[])
{
	
	LOG ("Info ", "my test info.");
	LOG ("Error ", "my test error.");
	LOG ("Debug ", "my test debug.");
	return 0;
}

void my_test_log(const char *prefix, const char *string)
{
	char dummy[100];
	strcpy(dummy,"Test :");
	strcat(dummy,prefix);
	printf("%s\n", strcat(dummy, string));
}