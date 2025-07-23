#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", a + b);
  while (scanf("%d %d", &a, &b) != EOF)
    printf("\n%d\n", a + b);
  return 0;
}
