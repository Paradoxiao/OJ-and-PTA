
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

  int *ar = (int *)malloc(sizeof(int) * 10000000);
  for (int m = 0; m < 10000000; m++)
    ar[m] = 0;
  int h, i, j, k;
  for (i = 2; i <= sqrt(10000000); i++)
    if (ar[i] == 0)
      for (j = 2 * i; j < 10000000; j += i)
        ar[j] = 1;
  while (scanf("%d", &k) != EOF) {
    h = 0, i = 2;
    while (1) {
      if (ar[i] == 0)
        h++;
      if (h == k) {
        printf("%d\n", i);
        break;
      }
      i++;
    }
  }
}
