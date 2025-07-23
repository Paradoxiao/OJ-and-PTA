#include <stdio.h>
#define MAX_STR_LEN 100
int strToInt(char str[], int base) {
  int num = 0, sig = 1, i = 0;
  if (str[0] == '-') {
    sig = -1;
    i++;
  }
  if (str[0] == '+') {
    sig = 1;
    i++;
  }
  switch (base) {
  case 2:
    for (; str[i] != '\0' && str[i] != '\r'; i++)
      if (str[i] == '1' || str[i] == '0')
        num = num * 2 + str[i] - '0';
    break;
  case 8:
    for (; str[i] != '\0' && str[i] != '\r'; i++)
      if (str[i] >= '0' && str[i] <= '7')
        num = num * 8 + str[i] - '0';
    break;
  case 10:
    for (; str[i] != '\0' && str[i] != '\r'; i++)
      if (str[i] >= '0' && str[i] <= '9')
        num = num * 10 + str[i] - '0';
    break;
  case 16:
    for (; str[i] != '\0' && str[i] != '\r'; i++) {
      if (str[i] >= '0' && str[i] <= '9')
        num = num * 16 + str[i] - '0';
      if (str[i] >= 'A' && str[i] <= 'F')
        num = num * 16 + str[i] - 'A' + 10;
      if (str[i] >= 'a' && str[i] <= 'f')
        num = num * 16 + str[i] - 'a' + 10;
    }
    break;
  default:
    return 0;
  }
  return num * sig;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int base;
  char s[MAX_STR_LEN];
  while ((scanf("%d:", &base) != EOF) && (gets(s) != NULL))
    printf("%d\n", strToInt(s, base));
  return 0;
}