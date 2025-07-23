#include <stdio.h>
int main() {
  int a, n = 1, maxn = 1, max;
  scanf("%d", &a);
  max = a;
  while (scanf("%d", &a) != EOF) {
    n++;
    if (max < a) {
      max = a;
      maxn = n;
    }
  }
  printf("max = %d, order = %d.", max, maxn);
  return 0;
}