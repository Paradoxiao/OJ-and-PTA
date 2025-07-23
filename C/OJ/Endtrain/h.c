#include <stdio.h>
#include <stdlib.h>
int str_num(char s[]) { return atoi(s); }
int main() {
  char s[20];
  scanf("%s", s);
  printf("%d\n", str_num(s));
}