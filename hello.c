#include <stdio.h>
#include <stdlib.h>
#define DYN _var
#define TEST(X) "YOU ", (X) ? "Rose" : ""
#define MAX 20 
#define EXTRA 10
#define RESIZE(VAR, SIZE) VAR=(char*)malloc((SIZE) * sizeof (char *))
#define DODEF(T) \
    do {\
      RESIZE(T, MAX)\
      ; \
      i+=sprintf(T, frmt , 'I', 35)\
      ;\
        if(sprintf(T+i, "%s%s\n", TEST (DYN)) > MAX)\
          {\
            RESIZE(T, MAX+EXTRA)\
            ;\
            sprintf(T+i, "%s%s\n\n", TEST (DYN))\
            ;\
          }\
    } while(0)

int _var = 0;

int main() {
  char *test;
  unsigned char i = 0;
  char frmt[25] = "\n%c %c ";

#ifdef FLAG // defined dynamically
  _var = 1;
#endif
  DODEF (test);
  printf(test);
  /*printf("\n");*/
  return 0;
}
