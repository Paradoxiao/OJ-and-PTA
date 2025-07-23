#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    double x;
    scanf("%lf", &x);
    printf("%.2lf\n",
           (pow((1 + x * x), x) * (log(1 + x * x) + 2 * x * x / (1 + x * x))));
  }
  return 0;
}