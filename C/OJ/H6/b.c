#include <limits.h>
#include <stdio.h>
#define LL lon\
g lon\
g
int main() {
  int n;
  LL sum = 0;
  char m;
  scanf("%d", &n);
  while (n--) {
    scanf(" %c", &m);
    if (m >= '0' && m <= '9') {
      sum *= 10;
      sum += m - '0';
    }
    if (sum > INT_MAX) {
      printf("Overflow");
      return 0;
    }
  }
  printf("%lld", sum);
  return 0;
}