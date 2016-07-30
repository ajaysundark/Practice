#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str1[]= "Eth 1/1";
	char str2[]= "Ve 40";
    char str3[40] = {0};

    strncpy(str3, str1, strlen(str1));
    printf("%s\nLen: %d\n", str3, strlen(str3));
    strcpy(str3, str2);
    printf("%s\nLen: %d\n", str3,strlen(str3));
	return 0;
}
