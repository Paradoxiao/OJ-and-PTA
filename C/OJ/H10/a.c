#include <stdio.h>
#include <string.h>
int check(char str[]) {
  char avoid[20][20] = {
      "int",  "double",  "float", "for",    "if",       "while",   "do",
      "goto", "switch",  "break", "int\r",  "double\r", "float\r", "for\r",
      "if\r", "while\r", "do\r",  "goto\r", "switch\r", "break\r"};
  if (str[0] >= '0' && str[0] <= '9')
    return 0;
  for (int i = 0; i < 20; i++)
    if (strcmp(str, avoid[i]) == 0)
      return 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (!((str[i] >= 'a' && str[i] <= 'z') ||
          (str[i] >= 'A' && str[i] <= 'Z') ||
          (str[i] >= '0' && str[i] <= '9') || str[i] == '_' || str[i] == '\r'))
      return 0;
  }
  return 1;
}
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  char string[20];
  while (gets(string)) {
    check(string) ? puts("yes") : puts("no");
  }
  return 0;
}