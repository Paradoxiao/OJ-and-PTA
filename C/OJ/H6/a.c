#include <limits.h>
#include <stdio.h>
#define LL lon\
g lon\
g
int main() {
  LL n, m, sum = 0, presum;
  scanf("%lld", &n);
  while (n--) {
    scanf("%lld", &m);
    sum *= 10;
    sum += m;
    if (sum >INT_MAX) {
      printf("Overflow");
      return 0;
    }
    presum = sum;
  }
  printf("%lld", sum);
  return 0;
}