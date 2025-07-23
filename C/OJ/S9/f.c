#include <stdio.h>
void fun(int m) {
  if (!(m % 2)) {
    int temp = m * m * m, first = 1;
    int tmp = temp / m;
    for (int i = tmp - m + 1; i <= tmp + m - 1; i += 2) {
      printf(first ? "%d" : " + %d", i);
      first = 0;
    }
    return;
  }
  int a = 1, aa = 1, n = 1;
  int sum = 0, first = 1;
  while (1) {
    aa = a;
    for (int l = 0; l < m; l++) {
      sum += aa;
      aa += 2;
    }
    if (sum == m * m * m) {
      for (int i = a, l = 0; l < m; l++, i += 2) {
        printf(first ? "%d" : " + %d", i);
        first = 0;
      }
      break;
    }
    a += 2;
    sum = 0;
  }
}
int main() {
  int m;
  scanf("%d", &m);
  printf("%d^3 = ", m);
  fun(m);
  return 0;
}
