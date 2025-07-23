#include <stdio.h>
#include <stdlib.h>
void mulmatrix(int a[105][105], int b[105][105], int m1, int n1, int m2, int n2,
               int c[105][105]) {
  for (int i = 0; i < m1; i++)
    for (int l = 0; l < n2; l++) {
      c[i][l] = 0;
      for (int k = 0; k < n1; k++)
        c[i][l] += a[i][k] * b[k][l];
    }
}
void inmatrix(int a[105][105], int m, int n) {
  for (int i = 0; i < m; i++)
    for (int l = 0; l < n; l++)
      scanf("%d", &a[i][l]);
}
void outmatrix(int a[105][105], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int l = 0; l < n; l++)
      printf(!l ? "%d" : " %d", a[i][l]);
    printf("\n");
  }
  printf("\n");
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int m, n, p;
  int a[105][105] = {0}, b[105][105] = {0}, c[105][105] = {0};
  scanf("%d %d %d", &m, &n, &p);
  inmatrix(a, m, n);
  inmatrix(b, n, p);
  mulmatrix(a, b, m, n, n, p, c);
  outmatrix(c, m, p);
  return 0;
}