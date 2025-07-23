#include <stdio.h>
#include <stdlib.h>
int main() {
  int in = 0, out = 0, n, num;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &num);
    if (num >= 0)
      in += num;
    else
      out += num;
  }
  printf("%d %d", in, out);
  return 0;
}