#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  unsigned long long s;
  scanf("%llu", &s);
  unsigned long long n = sqrt(s);
  for (unsigned long long a = n; a > 0; a--) {
    unsigned long long b = s / a;
    if (a * b == s) {
      printf("%llu", 2 * (a + b));
      break;
    }
  }
  return 0;
}