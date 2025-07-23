#include <stdio.h>
#include <stdlib.h>
int h(int n, int x) {
  if (n == 0)
    return 1;
  if (n == 1)
    return x * 2;
  if (n > 1)
    return 2 * x * h(n - 1, x) - 2 * (n - 1) * h(n - 2, x);
  return 0;
}
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  printf("%d", h(n, x));
  return 0;
}