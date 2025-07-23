#include <stdio.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i = 0;
    while (n) {
      if (n & 1)
        i++;
      n >>= 1;
    }
    printf("%d\n", i);
  }
  return 0;
}