#include <stdio.h>
int add() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a || b) {
    printf("%d\n", a + b);
    add();
  }
}
int main() {
  int N;
  add();
}
