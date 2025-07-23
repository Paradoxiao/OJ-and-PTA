#include <stdio.h>
#define MAX_STR_LEN 20
int strToInt(char str[]) {
  if (str[0] == '\0' || str[0] == '\r')
    return -1;
  if (!(str[0] >= '0' && str[0] <= '9')) {
    return 0;
  }
  int num = 0;
  for (int i = 0; str[i] != '\0' && str[i] != '\r'; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      num = num * 10 + str[i] - '0';
    } else
      break;
  }
  return num;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char s[MAX_STR_LEN];
  while (gets(s) != NULL)
    printf("%d\n", strToInt(s));
  return 0;
}