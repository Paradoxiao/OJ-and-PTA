#include <stdio.h>
int max(int a, int b, int c) { return a > b ? a > c ? a : c : b > c ? b : c; }
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", max(a, b, c));
}