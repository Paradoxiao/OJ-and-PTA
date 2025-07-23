#include <stdio.h>
int main() {
  char ch[4];
  double high, low, step;
  scanf("%c%c%c%c", &ch[0], &ch[1], &ch[2], &ch[3]);
  scanf("%lf %lf %lf", &high, &low, &step);
  if (high < low) {
    double temp;
    temp = low;
    low = high;
    high = temp;
  }
  printf("   %c  ->    %c\n", ch[0], ch[3]);
  for (double i = low; i <= high + 1e-6; i += step) {
    if (ch[0] == 'C')
      printf("%5.1lf -> %5.1lf\n", i, (9 * i + 160) / 5);
    if (ch[0] == 'F')
      printf("%5.1lf -> %5.1lf\n", i, (i - 32) * 5 / 9);
  }
  return 0;
}