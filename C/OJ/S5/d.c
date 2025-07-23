#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d %d", &a, &b);
  if (a > b) {
    c = a;
    a = b;
    b = c;
  }
  c = 1;
  int i, n;
  for (i = a; i <= b; i++) {
    for (n = 2; n < i; n++) {
      if (i % n == 0)
        break;
    }
    if (i == n) {
      if (c) {
        printf("%d", i);
        c = 0;
      } else
        printf(" %d", i);
    }
  }
  return 0;
}
