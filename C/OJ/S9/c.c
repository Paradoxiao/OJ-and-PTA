#include <stdio.h>
#include <stdlib.h>
int YangHui(int x, int y) {
  if (x < 0 || y < 0)
    return 0;
  if (!x && !y)
    return 1;
  return YangHui(x - 1, y) + YangHui(x - 1, y - 1);
}
int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%d", YangHui(x, y));
  return 0;
}