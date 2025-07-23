
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int *ar = (int *)malloc(sizeof(int) * 1000000);
  for (int m = 0; m < 1000000; m++)
    ar[m] = 0;
  int h, i, j, k, l, flag;
  for (i = 2; i <= sqrt(1000000); i++)
    if (ar[i] == 0)
      for (j = 2 * i; j < 1000000; j += i)
        ar[j] = 1;
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    flag = 1;
    for (l = m; l <= n; l++) {
      if (l == 0 || l == 1)
        continue;
      if (ar[l] == 0) {
        printf("%d\n", l);
        flag = 0;
      }
    }
    if (flag)
      printf("\n");
    printf("\n");
  }
}
