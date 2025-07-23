#include <stdio.h>
int main() {
  double data, psum = 0, nsum = 0;
  int pn = 0, nn = 0;
  while (1) {
    scanf("%lf", &data);
    if (!data)
      break;
    if (data > 0) {
      pn++;
      psum += data;
    } else {
      nn++;
      nsum += data;
    }
  }
  if (nn) {
    printf("%d %.2lf\n", nn, nsum / nn);
  } else {
    printf("0\n");
  }
  if (pn) {
    printf("%d %.2lf\n", pn, psum / pn);
  } else {
    printf("0\n");
  }
  return 0;
}