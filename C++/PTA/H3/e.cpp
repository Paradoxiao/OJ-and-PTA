#include <stdio.h>
void hanoi(int n, char a, char b, char c) {
  if (n == 1) {
    printf("%c->%c\n", a, c);
    return;
  }
  hanoi(n - 1, a, c, b);
  printf("%c->%c\n", a, c);
  hanoi(n - 1, b, a, c);
}

int main() {
  int n;
  char a = '1', b = '2', c = '3';
  scanf("%d", &n);
  hanoi(n, a, b, c);
  printf("\n");
}

/* 请在这里填写答案 */