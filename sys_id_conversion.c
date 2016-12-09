#include <stdio.h>
#include <string.h>
#define BIG_ENDIAN

int main(int argc, char const *argv[])
{
	int i;
	char sysid[] = "\020%\021\001\023";
	char sptr_string[16]= {0};
	char *sptr_string1 = sptr_string;
	
	union ushort_t {
        unsigned char b[2];
        unsigned short int si;
    } ushort;

        for (i = 0; i < 3; i++) {
                ushort.b[0] = sysid[(2*i)+1];
                ushort.b[1] = sysid[(2*i)];
                printf("%4x.\n", ushort.si);
                sprintf(sptr_string1, "%4x.", ushort.si);
                sptr_string1+=5;
        }
        sptr_string[strlen(sptr_string)-1] = '\0'; // remove the last dot
        printf("%s\n", sptr_string);
	return 0;
}