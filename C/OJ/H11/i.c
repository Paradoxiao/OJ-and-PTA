#include <stdio.h>
void put_sum(int a, int b) { printf("%d\n", a + b); }
int main() {
  int a, b;

  while (scanf("%d%d", &a, &b) != EOF)
    put_sum(a, b);

  return 0;
}