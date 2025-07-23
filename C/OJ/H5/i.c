#include <stdio.h>
int main() {
  int n;
  long long temp = 1, sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    temp *= i;
    sum += temp;
    if (sum > 0xffffffff) {
      printf("overflow");
      return 0;
    }
  }
  printf("%lld", sum);
  return 0;
}