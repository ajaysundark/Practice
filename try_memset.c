#include <stdio.h>
#include <string.h>

int main()
{
  unsigned char u[6];
  int i;
  memset(u, -1, 6);
  // puts(u);
  for (i=0; i<6; ++i)
    printf("%x\n", u[i]);
  return 0;
}
