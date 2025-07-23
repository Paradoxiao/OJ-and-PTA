#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  double sum = 0, temp;
  while (n--) {
    scanf("%lf", &temp);
    for (double i = 1; i <= temp; i++)
      sum += 1 / i;
    printf("sum = %.6lf\n", sum);
    sum = 0;
  }
  return 0;
}
