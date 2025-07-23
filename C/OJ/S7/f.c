#include <stdio.h>
#include <stdlib.h>
int main() {
  double data[1005], avg, sum = 0;
  int N, first = 1;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", data + i);
    sum += data[i];
  }
  avg = sum / N;
  for (int i = 0; i < N; i++) {
    printf(first ? "%.2lf" : " %.2lf", data[i] - avg);
    first = 0;
  }
  return 0;
}