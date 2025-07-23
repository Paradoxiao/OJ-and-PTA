#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char s[105][100];
  int i = 0;
  while (scanf("%s", s[i++]) != EOF)
    ;
  for (int l = 0; l < i - 1; l++) {
    for (int m = 0; m < i - l - 1; m++) {
      if (strcmp(s[m], s[m + 1]) > 0) {
        char temp[100];
        strcpy(temp, s[m]);
        strcpy(s[m], s[m + 1]);
        strcpy(s[m + 1], temp);
      }
    }
  }
  for (int l = 0; l < i; l++) {
    if (strcmp(s[l], "\0"))
      printf("%s\n", s[l]);
  }
  return 0;
}