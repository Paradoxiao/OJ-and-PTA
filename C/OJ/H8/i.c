#include <stdio.h>
int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int count, n, a, b;
  int num[10001];
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    scanf("%d", num + i);
  }
  while (scanf("%d %d", &a, &b) != EOF) {
    int flag = 1, first = 1;
    if (a > b) {
      n = a;
      a = b;
      b = n;
    }
    for (int i = a; i <= b; i++) {
      if (i >= 1 && i <= count) {
        printf(first ? "%d" : " %d", num[i - 1]);
        first = 0;
        flag = 0;
      }
    }
    flag ? printf("OUT OF RANGE\n") : printf("\n");
  }
  return 0;
}