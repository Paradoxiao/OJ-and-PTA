#include <stdio.h>
int print(int m, int n) {
  for (int i = 1; i <= m; i++) {
    for (int l = 1; l <= n; l++)
      putchar(" *"[i == 1 || l == 1 || i == m || l == n]);
    putchar('\n');
  }
  return 0;
}
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  print(m, n);
}