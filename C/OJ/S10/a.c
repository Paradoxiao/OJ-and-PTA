#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int n, i = 0;
  scanf("%d", &n);
  getchar();
  char **str = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    char tmp[100001];
    gets(tmp);
    str[i] = (char *)malloc(strlen(tmp) + 1);
    strcpy(str[i], tmp);
  }
  for (int l = 0; l < n - 1; l++) {
    for (int m = 0; m < n - l - 1; m++) {
      if (strcmp(str[m], str[m + 1]) > 0) {
        char *temp = str[m];
        str[m] = str[m + 1];
        str[m + 1] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++)
    printf("%s\n", str[i]);
  return 0;
}