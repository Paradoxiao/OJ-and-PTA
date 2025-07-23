#include <stdio.h>
void get_num(int *a, int *b, int *c) { scanf("%d %d %d", a, b, c); }
void max_min(int *mmax, int *mmin, int a, int b, int c) {
  int max = a, min = b;
  *mmax = a > b ? a > c ? a : c : b > c ? b : c;
  *mmin = a < b ? a < c ? a : c : b < c ? b : c;
}
int main() {
  int cases, i;
  int mmax, mmin, a, b, c;

  scanf("%d", &cases);
  for (i = 1; i <= cases; i++) {
    get_num(&a, &b, &c);
    max_min(&mmax, &mmin, a, b, c);
    printf("case %d : %d, %d\n", i, mmax, mmin);
  }
}
