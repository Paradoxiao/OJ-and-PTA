#include <stdio.h>
int is_daffodil(int n) {
  if (!(n >= 100 && n < 1000))
    return 0;
  int a = n / 100, b = n / 10 % 10, c = n % 10;
  return a * a * a + b * b * b + c * c * c == n ? 1 : 0;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%s", (is_daffodil(n) ? "Yes, it is a daffodil."
                               : "No, it is not a daffodil."));
  return 0;
}