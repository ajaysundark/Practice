#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Brute force. N*power(N) */
void dopermute (char instr[], char outbuf[], int bitmark[], int length, int currlen) {
	if (currlen>=length)
	{
		printf("%s\n", outbuf);
	}

	for (int i = 0; i < length; ++i)
	{
		if (bitmark[i]) 
			/* character used already */
			continue;

		outbuf[currlen] = instr[i];
		bitmark[i] = 1; // mark this char as used in the bit position
		dopermute (instr, outbuf, bitmark, length, currlen+1);
		bitmark[i] = 0; // we unset this char for usable for next permutation
	}
}

int main(int argc, char const *argv[])
{
	char test[] = "fun";
	int len = strlen(test);

	char *outbuf = (char *) malloc (len+1);
	if (!outbuf)
		return EXIT_FAILURE;

	outbuf[len] = '\0';

	int *bitmark = (int *) calloc (len, sizeof(int)); // to hold the presence/absence details of a particular char in array
	if (!bitmark)
		return EXIT_FAILURE;

	dopermute (test, outbuf, bitmark, len, 0);

	free (bitmark);
	free (outbuf);
	return EXIT_SUCCESS;
}