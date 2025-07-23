#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char a[1005];
  scanf("%s", a);
  for (int i = 0; i < strlen(a); i++)
    putchar(a[strlen(a) - i - 1]);
  return 0;
}