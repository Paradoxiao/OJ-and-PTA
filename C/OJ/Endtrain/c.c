#include <stdio.h>
#include <stdlib.h>
int main() {
  int n = 0;
  char s[30];
  while (scanf("%s", s) != EOF)
    n++;
  printf("%d", n);
  return 0;
}