#include <stdio.h>
int main() {
  int N, sum, n;
  while (scanf("%d", &N) != EOF) {
    sum = 0;
    while (N--) {
      scanf("%d", &n);
      sum += n;
    }
    printf("%d\n", sum);
  }
}
