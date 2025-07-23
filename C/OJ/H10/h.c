#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 100
int strToInt(char str[], int base) {}
int main() {
  int base;
  char s[MAX_STR_LEN];
  while ((scanf("%d:", &base) != EOF) && (gets(s) != NULL))
    printf("%d\n", strToInt(s, base));
  return 0;
}
