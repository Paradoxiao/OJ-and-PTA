#include <stdio.h>
int main() {
  // freopen("in.txt", "r", stdin);
  int count, n;
  int a[10001];
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    scanf("%d", a + i);
  }
  while (scanf("%d", &n) != EOF) {
    if (n > count) {
      printf("OUT OF RANGE\n");
      continue;
    }
    printf("%d\n", a[n - 1]);
  }
  return 0;
}