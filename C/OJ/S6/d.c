#include <stdio.h>
void inverse(int n) {
  static int flag = 1;
  if (n % 10 == 0 && flag) {
  } else {
    printf("%d", n % 10);
    flag = 0;
  }
  if (n / 10)
    inverse(n / 10);
}
int main() {
  int n;
  scanf("%d", &n);
  inverse(n);
  return 0;
}