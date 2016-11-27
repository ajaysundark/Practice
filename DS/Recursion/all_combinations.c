#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void combinations_with_multiple_select (char in[], char outbuf[], int len, int currlen) {
	if (currlen>=len) {
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		outbuf[currlen] = in[i];
		printf("%s\n", outbuf);
		combinations_with_multiple_select (in, outbuf, len, currlen+1);
		outbuf[currlen] = '\0';
	}
}

void combinations_without_repeat (char in[], char outbuf[], int bitmask[], int len, int currlen) {
	if (currlen>=len) {
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		if (bitmask[i])
			continue;

		outbuf[currlen] = in[i];
		bitmask[i] = 1;
		printf("%s\n", outbuf);
		combinations_without_repeat(in, outbuf, bitmask, len, currlen+1);
		outbuf[currlen] = '\0';
		bitmask[i]=0;
	}
}

void combinations_comm (char in[], char outbuf[], int bitmask[], int len, int currlen, int curr_pos) {
	if (currlen>=len) {
		return;
	}

	for (int i = curr_pos; i < len; ++i)
	{
		if (bitmask[i])
			continue;

		outbuf[currlen] = in[i];
		bitmask[i] = 1;
		printf("%s\n", outbuf);
		combinations_comm(in, outbuf, bitmask, len, currlen+1, i);
		outbuf[currlen] = '\0';
		bitmask[i]=0;
	}
}

int combinations(char instr[]) {
	int len = strlen(instr);
	char *outbuf = (char *) calloc (len+1, sizeof(char));
	if (!outbuf)
		return EXIT_FAILURE;

	int *bitmask = (int *) calloc (len, sizeof(int));
	if (!bitmask)
		return EXIT_FAILURE;

	//combinations_with_multiple_select(instr, outbuf, len, 0);
	//combinations_without_repeat(instr, outbuf, bitmask, len, 0);
	combinations_comm (instr, outbuf, bitmask, len, 0, 0);

	return EXIT_SUCCESS;
}

int main(int argc, char const *argv[])
{
	char instr[] = "0123456789";
	int retval;
	clock_t t;
	t = clock();
	retval = combinations(instr);
	t = clock() - t;
	printf("Time taken for combinations generation is %f seconds\n", ((double)t)/CLOCKS_PER_SEC );
	return retval;
}