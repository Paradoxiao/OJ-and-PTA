#include <stdio.h>
int main() {
  int n, nn, i = 0, temp, tmp;
  scanf("%d", &n);
  nn = n * n;
  temp = tmp = n;
  while (n) {
    i++;
    n /= 10;
  }
  nn -= temp;
  temp = 1;
  for (int l = 0; l < i; l++) {
    temp *= 10;
  }
  if (nn % temp == 0)
    printf("%d", tmp);
}
