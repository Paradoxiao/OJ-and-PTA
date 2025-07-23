#include <stdio.h>
#include <stdlib.h>
int jiecheng(int a) { return a == 1 || a == 0 ? 1 : jiecheng(a - 1) * a; }
int Cnm(int m, int n) { return jiecheng(n) / jiecheng(m) / jiecheng(n - m); }
int main() {
  int M;
  while (scanf("%d", &M) != EOF) {
    printf("%d", M > 2 ? Cnm(M % 2 - 1, M) + M - 1 : M);
  }
  return 0;
}