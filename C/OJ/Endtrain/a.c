#include <stdio.h>
#include <stdlib.h>
int main() {
  int a, b, c, d;
  double aa, bb, cc;
  scanf("%d,%d", &a, &b);
  aa = a;
  bb = b;
  c = a / b;
  cc = aa / bb;
  d = a % b;
  printf("%d,%d\n%.2lf\n", c, d, cc);
  return 0;
}