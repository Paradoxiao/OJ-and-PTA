#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  switch (n) {
  case 1:
    puts("Monday");
    break;
  case 2:
    puts("Tuesday");
    break;
  case 3:
    puts("Wednesday");
    break;
  case 4:
    puts("Thursday");
    break;
  case 5:
    puts("Friday");
    break;
  case 6:
    puts("Saturday");
    break;
  case 7:
    puts("Sunday");
    break;
  default:
    puts("input error!");
    break;
  }
  return 0;
}