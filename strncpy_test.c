#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str1[]= "abc123";
    char str2[4] = {0};
    char str3[5] = "aa123";

    strncpy(str2, str1, strlen(str1));
    printf("%s\nLen: %d\n\n", str2, strlen(str2)); /* This is why strncpy is dangerous, it will not append NULL here at the end, and could result in unexpected results*/

    strncpy(str2, str3, strlen(str3));
    str2[4] = '\0';
    printf("%s\nLen: %d\n\n", str2, strlen(str2));

    strcpy(str2, str1);
    printf("%s\nLen: %d\n\n", str2,strlen(str2)); /* but, still, at some places, strcpy is better than strncpy */
	return 0;
}
