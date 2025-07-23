#include <stdio.h>
int main() {
  int a, aa, aaa;
  while (1) {
    aa = a;
    if (scanf("%d", &a) == EOF)
      break;
    aaa = aa;
  }
  printf("%d", aaa);
  return 0;
}