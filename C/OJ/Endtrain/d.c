#include <stdio.h>
#include <stdlib.h>
int main() {
  int a[4][4];
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      scanf("%d", &a[i][j]);
  int det = a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] +
            a[2][1] * a[3][2] * a[1][3] - a[1][1] * a[2][3] * a[3][2] -
            a[1][2] * a[2][1] * a[3][3] - a[1][3] * a[2][2] * a[3][1];
  printf("%d", det);
  return 0;
}