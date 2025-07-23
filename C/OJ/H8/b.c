#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int n, a[1005] = {0}, b[1005] = {0}, c[1005] = {0};
  int cil = 0, i, l, g, count;
  scanf("%d", &count);
  while (count--) {
    cil++;
    if (cil % 2) {
      memset(a, 0, sizeof(a));
      for (i = 0;; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0)
          break;
      }
    } else {
      memset(b, 0, sizeof(b));
      for (l = 0;; l++) {
        scanf("%d", &b[l]);
        if (b[l] == 0)
          break;
      }
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
  if (cil && cil % 2) {
    printf("%d", a[0]);
    for (g = 1; g < i; g++)
      printf(" %d", a[g]);
    printf("\n");
  }
  for (int tmp = 0; tmp < 1005; tmp++)
    if (cil && cil % 2 == 1 && !(a[tmp])) {
      printf("\n");
      break;
    }
  return 0;
}