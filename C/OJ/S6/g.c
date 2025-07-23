#include <stdio.h>
#include <stdlib.h>
void print(int n, char ch) {
  n /= 2;
  int flag = 1;
  for (int y = -n; y <= n; y++) {
    flag = 1;
    for (int x = -n; x <= n; x++)
      if (abs(y) + abs(x) <= n) {
        putchar(ch);
        flag = 0;
      } else {
        if (flag)
          putchar(' ');
      }

    putchar('\n');
  }
}
int main() {
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  print(n, ch);
  return 0;
}