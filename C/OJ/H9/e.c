#include <stdio.h>
#include <stdlib.h>
int main() {
  int M, N, max[10000], n, m, place;
  for (int i = 0;; i++) {
    int l;
    place = 0;
    if (scanf("%d", &N) == EOF) {
      M = i;
      break;
    }
    scanf("%d", &m);
    for (l = 1; l < N; l++) {
      scanf("%d", &n);
      if (n > m) {
        m = n;
        place = l;
      }
    }
    max[i] = m;
    printf("Case %d: max=%d, pos=%d.\n", i + 1, m, place + 1);
  }
  place = 0;
  m = max[0];
  for (int i = 0; i < M; i++) {
    if (max[i] > m) {
      m = max[i];
      place = i;
    }
  }
  printf("max of all is %d of %d row.", m, place + 1);
  return 0;
}