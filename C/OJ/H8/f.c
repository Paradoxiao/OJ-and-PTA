#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  // freopen("in.txt", "r", stdin);
  int count, n;
  int a[10001];
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    scanf("%d", a + i);
  }
  while (scanf("%d", &n) != EOF) {
    int flag = 1;
    for (int i = count; i >= 0; i--)
      if (a[i] == n) {
        printf("%d\n", i + 1);
        flag = 0;
        break;
      }
    if (flag)
      printf("NOT FOUND\n");
  }
  return 0;
}