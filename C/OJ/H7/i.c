#include <stdio.h>
int main() {
  int N, sum, n, nn;
  scanf("%d", &nn);
  while (nn--) {
    scanf("%d", &N);
    sum = 0;
    while (N--) {
      scanf("%d", &n);
      sum += n;
    }
    printf("%d\n", sum);
  }
}
