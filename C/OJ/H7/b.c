#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    int n;
    unsigned int i = 0;
    while (1) {
      scanf("%d", &n);
      if (n == -1)
        break;
      i = i * 10 + n;
    }
    printf("%u\n", i);
  }
}
