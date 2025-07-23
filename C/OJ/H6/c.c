#include <limits.h>
#include <stdio.h>
int main() {
  int block = 1, sum = 0;
  char m;
  while (scanf(" %c", &m)!=EOF) {
    if (m >= '0' && m <= '9') {
      sum *= 10;
      sum += m - '0';
    }
    if (sum > INT_MAX || sum < 0) {
      printf("Overflow");
      block = 0;
      break;
    }
  }
  if (block)
    printf("%d", sum);
  return 0;
}