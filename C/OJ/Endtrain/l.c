#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int bit[1000];
} big_int;
big_int carry(big_int a) {
  for (int i = 0; i < 1000; i++)
    if (a.bit[i] > 9) {
      a.bit[i + 1] += a.bit[i] / 10;
      a.bit[i] %= 10;
    }
  return a;
}
big_int add(big_int a, big_int b) {
  for (int i = 0; i < 1000; i++)
    a.bit[i] += b.bit[i];
  return carry(a);
}
big_int mul(big_int a, int n) {
  for (int i = 0; i < 1000; i++)
    a.bit[i] *= n;
  return carry(a);
}
void out_int(big_int a) {
  int i = 999;
  while (!a.bit[i])
    i--;
  for (; i >= 0; i--)
    printf("%d", a.bit[i]);
}
int main() {
  big_int a, sum;
  memset(a.bit, 0, sizeof(a.bit));
  memset(sum.bit, 0, sizeof(a.bit));
  a.bit[0] = 1;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    a = mul(a, i);
    sum = add(sum, a);
  }
  out_int(sum);
  return 0;
}