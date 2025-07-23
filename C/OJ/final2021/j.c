#include <stdio.h>
#include <string.h>
void str_sep(char s[], char t[], char r[]) {
  int a = 0, b = 0;
  for (int i = 0; i < strlen(r); i++) {
    if (i % 2)
      t[a++] = r[i];
    else
      s[b++] = r[i];
  }
  t[strlen(r)] = 0;
  s[strlen(r)] = 0;
}

int main() {
  char r[101], s[101], t[101];
  gets(r);
  str_sep(s, t, r);
  puts(s);
  puts(t);
  return 0;
}
