#include <stdio.h>
int main() {
  int a, b;
  char ch;
  while (1) {
    scanf("%d%c%d", &a, &ch, &b);
    if (a == 0 && b == 0 && ch == ' ')
      break;
    switch (ch) {
    case '+':
      printf("%d\n", a + b);
      break;
    case '-':
      printf("%d\n", a - b);
      break;
    case '*':
      printf("%d\n", a * b);
      break;
    case '/':
      printf("%d\n", a / b);
      break;
    case '%':
      printf("%d\n", a % b);
      break;
    default:
      printf("invalid op\n");
      break;
    }
  }
  return 0;
}