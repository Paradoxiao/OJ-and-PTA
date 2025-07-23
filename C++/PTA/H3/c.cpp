#include <stdio.h>

void dectobin(int n) {
  if (n > 1)
    dectobin(n / 2);
  putchar("01"[n % 2]);
}

int main() {
  int n;

  scanf("%d", &n);
  dectobin(n);

  return 0;
}

/* 你的代码将被嵌在这里 */