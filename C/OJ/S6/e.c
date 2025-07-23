#include <stdio.h>
void f(int a, int b, int c) {
  double d = a, e = b, f = c;
  printf("%.3lf", d / (e + f));
}
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  f(a, b, c);
  return 0;
}