#include <stdio.h>
#include <stdlib.h>
struct time {
  int y, m, d;
};
int cmp_time(const void *a, const void *b) {
  return ((struct time *)a)->y * 3600 + ((struct time *)a)->m * 60 +
         ((struct time *)a)->d - ((struct time *)b)->y * 3600 -
         ((struct time *)b)->m * 60 - ((struct time *)b)->d;
}
int get_time(struct time tm[]) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d %d", &tm[i].y, &tm[i].m, &tm[i].d);
  return n;
}
int sort_time(struct time tm[], int n) {
  qsort(tm, n, sizeof(struct time), cmp_time);
}
int put_time(struct time tm[], int n) {
  for (int i = 0; i < n; i++)
    printf("%02d:%02d:%02d\n", tm[i].y, tm[i].m, tm[i].d);
}
int main() {
  struct time tm[100];
  int i, n;
  n = get_time(tm);
  sort_time(tm, n);
  put_time(tm, n);
}