#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    int n;
    unsigned int i = 0;
    int sign;
    scanf("%d", &sign);
    while (1) {
      scanf("%d", &n);
      if (n == -1)
        break;
      i = i * sign + n;
    }
    printf("%u\n", i);
  }
}
