#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int A(int m, int n) {
  if (m == 0)
    return n + 1;
  if (m > 0 && n == 0)
    return A(m - 1, 1);
  if (m > 0 && n > 0)
    return A(m - 1, A(m, n - 1));
  return 0;
}
int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF)
    printf("%d\n", A(m, n));
  return 0;
}