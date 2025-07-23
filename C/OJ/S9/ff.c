#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 1000
int str_cmp(char *s1, char *s2) {
  while (*s1 == *s2 ||
         (*s1 >= 'A' && *s1 <= 'Z' && *s2 >= 'a' && *s2 <= 'z' &&
          *s1 - 'A' == *s2 - 'a') ||
         (*s2 >= 'A' && *s2 <= 'Z' && *s1 >= 'a' && *s1 <= 'z' &&
          *s2 - 'A' == *s1 - 'a')) {
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
int main() {
  char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
  while ((gets(str1) != NULL) && (gets(str2) != NULL))
    printf("%d\n", str_cmp(str1, str2));
  return 0;
}