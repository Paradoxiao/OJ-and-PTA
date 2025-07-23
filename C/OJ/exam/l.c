#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    unsigned long long int a = 1;
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 13 || n == 17 || n == 19 ||
        n == 31 || n == 61) {
      for (int i = 0; i < n; i++)
        a *= 2;
      printf("%llu\n", a - 1);
    } else
      puts("no");
  }
  return 0;
}