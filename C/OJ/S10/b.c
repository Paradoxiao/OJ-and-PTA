
#include <stdio.h>
#include <stdlib.h>
int main() {
  int *ar = (int *)malloc(sizeof(int) * 10000000);
  for (int m = 0; m < 10000000; m++)
    ar[m] = 0;
  int h, i, j, k;
  for (i = 2; i * i <= 10000000; i++)
    if (!(ar[i]))
      for (j = 2 * i; j < 10000000; j += i)
        ar[j] = 1;
  while (scanf("%d", &k) != EOF) {
    h = 0, i = 2;
    while (1) {
      if (!(ar[i]))
        h++;
      if (h == k) {
        printf("%d\n", i);
        break;
      }
      i++;
    }
  }
}
