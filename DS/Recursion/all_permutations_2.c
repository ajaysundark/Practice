#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char instr[], int indx_a, int indx_b) {
	char temp = instr[indx_a];
	instr[indx_a] = instr[indx_b];
	instr[indx_b] = temp;
}

void dopermute (char instr[], int length, int currpos) {
	if (currpos==length) {
		printf("%s\n", instr);
	}

	for (int i = currpos; i < length; ++i) {
		swap(instr, i, currpos);
		dopermute (instr, length, currpos+1);
		swap(instr, i, currpos);
	}
}

int main(int argc, char const *argv[])
{
	char test[] = "fun";
	int len = strlen(test);

	dopermute (test, len, 0);

	return EXIT_SUCCESS;
}