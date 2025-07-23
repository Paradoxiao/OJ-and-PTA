#include <stdio.h>
int main() {
  int n, a, flag;
  while (scanf("%d", &n) != EOF) {
    flag = 1;
    if (n % 7 == 0) {
      flag = 0;
      goto TO;
    }
    while (n) {
      a = n % 10;
      if (a == 7) {
        flag = 0;
        break;
      }
      n = n / 10;
    };
  TO:
    flag ? printf("YES\n") : printf("NO\n");
  }
  return 0;
}
