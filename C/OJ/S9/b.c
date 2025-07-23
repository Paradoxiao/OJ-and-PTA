#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 150
char *trim(char *s) {
  int left, l = 0, flag = 1;
  for (left = 0; isspace(s[left]); left++)
    flag = 0;
  if (flag) {
    return s;
  }
  for (int i = left; s[i] != '\0'; i++) {
    s[l++] = s[i];
  }
  s[l] = '\0';
  for (int i = l; i >= 0; i--) {
    if (isspace(s[i])) {
      s[i] = '\0';
    }
  }
  return s;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  char str[MAX_STR_LEN], *p;
  do {
    gets(str);
    p = trim(str);
    puts(p);
  } while (strcmp(p, "END"));
  return 0;
}
