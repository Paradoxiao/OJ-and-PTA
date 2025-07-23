#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  printf("    ");
  int i, j;
  for (i = 1; i <= n; i++) {
    printf("%5d", i);
  }
  printf("\n");
  for (i = 1; i <= n; i++) {
    printf("%4d", i);
    for (j = 1; j <= i; j++) {
      printf("%5d", i + j);
    }
    printf("\n");
  }
  return 0;
}
