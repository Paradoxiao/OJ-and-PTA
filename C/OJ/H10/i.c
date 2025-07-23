#include <stdio.h>
#define MAX_STR_LEN 100
double strToDouble(char str[]) {
  if (str[0] == '\0' || str[0] == '\r') {
    return 0;
  }
  double res = 0, dot = 0.1;
  int i = 0, flag = 1;
  if (str[0] == '-') {
    flag = -1;
    i++;
  }
  while (str[i] != '\0' && str[i] != '\r') {
    if (str[i] >= '0' && str[i] <= '9') {
      res = res * 10 + str[i] - '0';
    }
    if (str[i] == '.')
      while (str[i] != '\0' && str[i] != '\r') {
        if (str[i] >= '0' && str[i] <= '9') {
          res += (str[i] - '0') * dot;
          dot *= 0.1;
        }
        i++;
      }
    i++;
  }
  return res * flag;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char s[MAX_STR_LEN];
  while (gets(s) != NULL)
    printf("%lg\n", strToDouble(s));
  return 0;
}