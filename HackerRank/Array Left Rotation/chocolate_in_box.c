/* Timeout as for some inputs it exceeds 2s */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,i,j,count=0;
    int *arr, *xor_arr;
    
    scanf("%d", &n);
    
    arr = (int *) calloc (n, sizeof (int));
    xor_arr = (int *) calloc (n, sizeof (int));
    
    for(i=0;i<n;++i) {
       scanf("%d", &arr[i]);
       for(j=0;j<n;j++) {
           if(i==j) continue;
           xor_arr[j]^=arr[i];
       }
    }
    
    for(i=0;i<n;++i) {
        if(xor_arr[i]<arr[i]) ++count;
    }
    
    printf("%d", count);
    return 0;
}
