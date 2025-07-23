#include <stdio.h>
#include <stdlib.h>
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    getchar();
    while (N--) {
      char num[2000];
      gets(num);
      putchar(num[0]);
    }
    putchar('\n');
  }
  return 0;
}