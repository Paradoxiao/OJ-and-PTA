#include <stdio.h>

int f(int n) {
  if (!n)
    return 0;
  static int data[100] = {0, 1, 1};
  if (!data[n])
    data[n] = f(n - 1) + f(n - 2);
  return data[n];
}

int main() {
  int n;

  scanf("%d", &n);
  printf("%d\n", f(n));

  return 0;
}

/* 你的代码将被嵌在这里 */