#include <stdio.h>
#define MAX_STR_LEN 12
int strToInt(char str[]) {
  /*if (!((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '+')) {
    return 0;
  }*/
  int num = 0, sig = 1, i = 0;
  if (str[0] == '-') {
    sig = -1;
    i++;
  }
  if (str[0] == '+') {
    sig = 1;
    i++;
  }
  for (; str[i] != '\0' && str[i] != '\r'; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      num = num * 10 + str[i] - '0';
  }
  return num * sig;
}
/*int strToInt(char str[]) {
  int sign = 1, a, sum = 0, i = 0;
  if (str[0] == '-')
    sign = -1;
  if (str[0] == '+')
    sign = 1;
  if (str[0] == '\0' || str[0] == '\r')
    return -1;
  if (!(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
    return 0;
  while (str[i] != '\0') {
    a = str[i] - '0';
    if (a >= 0 && a <= 9)
      sum = sum * 10 + a;
    else if (!(a + '0' == '+' || a + '0' == '-'))
      return sum * sign;
    i++;
  }
  return sum * sign;
}*/
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char s[MAX_STR_LEN];
  while (gets(s) != NULL)
    printf("%d\n", strToInt(s));
  return 0;
}