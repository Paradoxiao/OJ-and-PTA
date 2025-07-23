#include <stdio.h>
char next(char ch) {
  if (ch == 'z')
    return 'a';
  if (ch == 'Z')
    return 'A';
  return ch + 1;
}
int main() {
  int m, i;
  char ch;
  scanf("%d", &m);
  getchar();
  for (i = 0; i < m; i++) {
    ch = getchar();
    putchar(next(ch));
  }
  return 0;
}
