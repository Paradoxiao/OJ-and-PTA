#include <stdio.h>
#include <stdlib.h>
int main() {
  unsigned long long n, k, mul = 1;
  scanf("%llu %llu", &n, &k);
  for (int i = 0; i < k; i++)
    mul *= n;
  printf("%llu\n", mul);
  return 0;
}