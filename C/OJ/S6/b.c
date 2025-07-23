#include <stdio.h>
#define MAX_STR_LEN 12
int strToInt(char str[]) {
  int sign = 1, a, sum = 0, i = 0;
  if (str[0] == '-')
    sign = -1;
  if (str[0] == '+')
    sign = 1;
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
}

int main() {
  char s[MAX_STR_LEN];
  while (gets(s) != NULL)
    printf("%d\n", strToInt(s));
  return 0;
}