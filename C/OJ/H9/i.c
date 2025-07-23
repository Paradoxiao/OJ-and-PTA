#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char passwd[25], input[25];
  int expression = 0;
  scanf("%s", passwd);
  while (scanf("%s", input) != EOF) {
    if (expression >= 5) {
      puts("Out of limited!");
      continue;
    }
    if (strcmp(passwd, input)) {
      puts("Wrong!");
      expression++;
    } else {
      puts("Welcome!");
      break;
    }
  }
  return 0;
}