#include <stdio.h>
int digit_sum(int num) {
  int result = 0;
  while (num) {
    result += num % 10;
    num /= 10;
  }
  if (!(result / 10))
    return result;
  result = digit_sum(result);
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", digit_sum(n));
  return 0;
}