#include <stdio.h>
int main() {
  int N, bit = 1, flag = 1;
  while (scanf("%d", &N) != EOF) {
    for (int k = 0; k < N; k++) {
      bit *= 10;
    }
    for (int g = bit / 10; g < bit; g++) {
      int n, nn, i = 0, temp, tmp;
      n = g;
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
      if (nn % temp == 0 && tmp) {
        if (flag) {
          printf("%d", tmp);
          flag = 0;
        } else
          printf(" %d", tmp);
      }
    }
    printf("\n");
    bit = flag = 1;
  }
}
