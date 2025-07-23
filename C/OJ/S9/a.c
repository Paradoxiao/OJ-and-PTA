#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 20
int getMax(int a[][MAX_LEN], int m, int n) {
  for (int i = 0; i < m; i++) {
    int temp = a[i][0];
    for (int l = 0; l < n; l++) {
      temp = abs(temp) >= abs(a[i][l]) ? temp : a[i][l];
    }
    printf("%d : %d\n", i, temp);
  }
}
int input(int a[][MAX_LEN], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int l = 0; l < n; l++) {
      scanf("%d", &a[i][l]);
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int a[MAX_LEN][MAX_LEN], m, n;
  scanf("%d%d", &m, &n);
  input(a, m, n);
  getMax(a, m, n);
  return 0;
}