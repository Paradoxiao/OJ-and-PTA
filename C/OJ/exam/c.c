#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    int num, max, min;
    scanf("%d", &num);
    max = min = num;
    for (int i = 1; i < n; i++) {
      scanf("%d", &num);
      if (num > max)
        max = num;
      if (num < min)
        min = num;
    }
    printf("%d %d\n", max, min);
  }
  return 0;
}