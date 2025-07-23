#include <math.h>
#include <stdio.h>
double func(double x) {
  if (x < 0)
    return -x;
  if (x >= 0 && x < 1)
    return sin(2 * x);
  if (x >= 1 && x < 5)
    return sqrt(x * x * x + x);
  return x * 2 + 10;
}
int output(int n, double x) {
  printf("case %d:y=%.6lg.\n", n, x);
  return 0;
}
int main() {
  int i, cases;
  double x;
  scanf("%d", &cases);
  for (i = 1; i <= cases; i++) {
    scanf("%lf", &x);
    output(i, func(x));
  }
  return 0;
}