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
    int i;
    for (i = 0; i < count; i++) {
      if (a[i] == n) {
        printf("%d\n", i + 1);
        break;
      }
    }
    if (i == count) {
      printf("NOT FOUND\n");
      continue;
    }
  }
  return 0;
}