#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  freopen("in.txt", "r", stdin);
  int *a, *b, *c;
  a = (int *)malloc(sizeof(int) * 1001);
  b = (int *)malloc(sizeof(int) * 1001);
  c = (int *)malloc(sizeof(int) * 1001);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  int d, s, count, i = 0, j = 0, temp, k = 0;
  scanf("%d", &count);
  while (count--) {
    k++;
    i = j = 0;
    while (1) {
      scanf("%d", &temp);
      if (!temp)
        break;
      if (k % 2) {
        a[i] = temp;
        i++;
      } else {
        b[i] = temp;
        j++;
      }
    }
    if (!(k % 2)) {
      if (i > j) {
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
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
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
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
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
