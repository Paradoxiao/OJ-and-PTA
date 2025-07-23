#include <stdio.h>
int A(int m, int n) {
  static int data[5][1000000000] = {0};
  if (!data[m][n]) {
    if (m == 0) {
      data[m][n] = n + 1;
      return data[m][n];
    }
    if (m > 0 && n == 0) {
      data[m][n] = A(m - 1, 1);
      return data[m][n];
    }
    if (m > 0 && n > 0) {
      data[m][n] = A(m - 1, A(m, n - 1));
      return data[m][n];
    }
  }
  return data[m][n];
}

int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    printf("%d\n", A(m, n));
  }
  return 0;
}