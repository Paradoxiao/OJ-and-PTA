#include <stdio.h>
int main() {
  double a, work, lab, point;
  scanf("%lf", &a);
  while (scanf("%lf %lf %lf", &work, &lab, &point) != EOF) {
    printf("%.4lf\n", point * a / (work + lab));
  }
  return 0;
}