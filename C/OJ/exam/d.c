#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char s[105], p[105];
  scanf("%s %s", s, p);
  int equal = 1;
  if (strlen(s) != strlen(p))
    equal = 0;
  else
    for (int i = 0; i < strlen(s); i++) {
      if (islower(s[i]))
        s[i] = toupper(s[i]);
      if (islower(p[i]))
        p[i] = toupper(p[i]);
    }
  equal = strcmp(s, p);
  puts(equal ? "no" : "yes");
  return 0;
}