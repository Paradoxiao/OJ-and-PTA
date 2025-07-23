#include <stdio.h>
int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int count, n;
  int a[10001];
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    scanf("%d", a + i);
  }
  while (scanf("%d", &n) != EOF) {
    int i, flag = 1, first = 1;
    for (i = 0; i < count; i++) {
      if (a[i] == n) {
        printf(first ? "%d" : " %d", i + 1);
        first = 0;
        flag = 0;
      }
    }
    if (flag) {
      printf("NOT FOUND\n");
      continue;
    } else {
      printf("\n");
    }
  }
  return 0;
}