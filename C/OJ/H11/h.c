#include <stdio.h>
int sum(int a, int b) { return a + b; }
int main() {
  int a, b;

  while (scanf("%d%d", &a, &b) != EOF)
    printf("%d\n", sum(a, b));

  return 0;
}