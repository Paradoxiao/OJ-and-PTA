#include <stdio.h>
#include <stdlib.h>
int main() {
  int a, b, n, result;
  scanf("%d %d %d", &a, &b, &n);
  for (int i = 0; i <= n; i++) {
    result = a / b;
    a = a % b * 10;
  }
  printf("%d", result);
  return 0;
}