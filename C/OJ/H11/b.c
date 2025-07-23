#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char s[200];
  int m, n, i, l;
  scanf("%s", s);
  scanf("%d %d", &m, &n);
  putchar('[');
  for (int i = m; i <= n; i++) {
    if (i >= 0 && i < (int)strlen(s) && s[i] != '\0')
      putchar(s[i]);
  }
  putchar(']');
  return 0;
}