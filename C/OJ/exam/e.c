#include <stdio.h>
#include <stdlib.h>
int num(int n) {
  static int p = 1;
  return n == 1 ? 1 : num(n - 1) + p++;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", num(n));
  return 0;
}