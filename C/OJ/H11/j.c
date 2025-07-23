#include <stdio.h>
int add(int n) {
  if (n--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    add(n);
  }
}
int main() {
  int N;
  scanf("%d", &N);
  add(N);
}