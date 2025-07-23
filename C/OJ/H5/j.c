#include <stdio.h>
int main() {
  int n, i = 32;
  scanf("%d", &n);
  if (n == 0) {
    printf("1");
    return 0;
  }
  unsigned int temp = 0x80000000;
  while (1) {
    if (temp & n) {
      printf("%d", i);
      break;
    }
    i--;
    temp >>= 1;
  }
  return 0;
}