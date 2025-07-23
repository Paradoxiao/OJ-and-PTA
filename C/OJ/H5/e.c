#include <stdio.h>
int main() {
  int n;
  int a, min = 0, max = 0;
  scanf("%d", &n);
  scanf("%d", &a);
  max = min = a;
  while (--n) {
    scanf("%d", &a);
    min = min < a ? min : a;
    max = max > a ? max : a;
  }
  printf("The maximum number is %d.\nThe minimum number is %d.\n", max, min);
  return 0;
} // Mental Omega Launch!!!