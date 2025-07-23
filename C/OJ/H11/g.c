#include <stdio.h>
#define MAX_STR_LEN 1000
char *str_cpy(char *t, char *s, int n) {
  char *p = t;
  while (n--) {
    *t++ = *s++;
  }
  *t = '\0';
  return p;
}
int main() {
  int n;
  char s[MAX_STR_LEN], str[MAX_STR_LEN], *p;
  while (scanf("%d", &n) != EOF && getchar()) {
    gets(s);
    p = str_cpy(str, s, n);
    puts(p);
    puts(str);
  }
  return 0;
}