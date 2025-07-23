#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  // freopen("in.txt", "r", stdin);
  int *a, *b, *c;
  a = (int *)malloc(sizeof(int) * 1001);
  b = (int *)malloc(sizeof(int) * 1001);
  c = (int *)malloc(sizeof(int) * 1001);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  int i, j, k = 0;
  int d;
  int s;
  int count;
  scanf("%d", &count);
  while (count--) {
    scanf("%d", &d);
    k++;
    if (k % 2) {
      memset(a, 0, sizeof(a));
      for (i = 0; i < d; i++)
        scanf("%d", a + i);
    } else {
      memset(b, 0, sizeof(b));
      for (j = 0; j < d; j++)
        scanf("%d", b + j);
    }
    if (k > 1) {
      if (i > j) {
        memset(c, 0, sizeof(c));
        for (s = 0; s < i; s++) {
          c[s] = a[s] + b[s];
        }
        for (s = 0; s < i; s++) {
          if (s == 0)
            printf("%d", c[0]);
          else
            printf(" %d", c[s]);
        }
        printf("\n");
      } else {
        for (s = 0; s < j; s++) {
          c[s] = a[s] + b[s];
        }
        for (s = 0; s < j; s++) {
          if (!s)
            printf("%d", c[0]);
          else
            printf(" %d", c[s]);
        }
        printf("\n");
      }
    }
  }
  if (d && k % 2 == 1)
    for (s = 0; s < i; s++) {
      if (!s)
        printf("%d", a[s]);
      else
        printf(" %d", a[s]);
    }
  printf("\n");
  if (!d && k % 2 == 1)
    printf("\n");
}
