#include <stdio.h>
#include <stdint.h>
uint32_t sum();

int main(int argc, char const *argv[])
{
	printf("%d\n", sum() );
	return 0;
}

uint32_t sum()
{
    uint16_t a = 65535;
    uint16_t b = 1;
    return a+b;
}