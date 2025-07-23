#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, a[1005] = {0}, b[1005] = {0}, c[1005] = {0};
  int cil = 0, i, l, g;
  while (scanf("%d", &n) != EOF) {
    cil++;
    if (cil % 2) {
      memset(a, 0, sizeof(a));
      for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    } else {
      memset(b, 0, sizeof(b));
      for (l = 0; l < n; l++)
        scanf("%d", &b[l]);
      if (!(cil % 2)) {
        if (i >= l) {
          memset(c, 0, sizeof(c));
          for (g = 0; g < i; g++)
            c[g] = a[g] + b[g];
          printf("%d", c[0]);
          for (g = 1; g < i; g++)
            printf(" %d", c[g]);
          printf("\n");
        } else {
          memset(c, 0, sizeof(c));
          for (g = 0; g < l; g++)
            c[g] = a[g] + b[g];
          printf("%d", c[0]);
          for (g = 1; g < l; g++)
            printf(" %d", c[g]);
          printf("\n");
        }
      }
    }
  }
  if (n && cil % 2) {
    printf("%d", a[0]);
    for (g = 1; g < i; g++)
      printf(" %d", a[g]);
    printf("\n");
  }
  if (!n && cil % 2 == 1)
    printf("\n");
  return 0;
}