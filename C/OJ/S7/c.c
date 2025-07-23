#include <stdio.h>
int digits(int n) {
  if (!n)
    return 1;
  int result = 0;
  while (n) {
    result++;
    n /= 10;
  }
  return result;
}
int main() {
  int num;
  scanf("%d", &num);
  printf("%d\n", digits(num));
}
