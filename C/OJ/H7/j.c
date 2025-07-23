#include <stdio.h>
int main() {
  int N, sum, n;
  while (1) {
    scanf("%d", &N);
    if (N == 0)
      break;
    sum = 0;
    while (N--) {
      scanf("%d", &n);
      sum += n;
    }
    printf("%d\n", sum);
  }
}
