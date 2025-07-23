#include <stdio.h>
#include <stdlib.h>
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int N, flag = 0;
  scanf("%d", &N);
  while (N--) {
    if (flag) {
      putchar('\n');
    } else {
      flag = 1;
    }
    int n, row, col, count = 0;
    scanf("%d", &n);
    int num[n + 5];
    for (int i = 0; i < n; i++) {
      scanf("%d", num + i);
    }
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++) {
      for (int l = 0; l < col; l++) {
        printf(l == 0 ? "%2d" : " %2d", num[count++]);
      }
      putchar('\n');
    }
  }
  return 0;
}