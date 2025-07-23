#include <stdio.h>
struct time {
  int h, m, s;
};
int get_time(struct time tm[]) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d %d", &tm[i].h, &tm[i].m, &tm[i].s);
  return n;
}
void exchange(struct time tm[], int x, int y) {
  struct time temp = tm[y];
  tm[y] = tm[x];
  tm[x] = temp;
}
int sort_time(struct time tm[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (tm[j].h > tm[j + 1].h)
        exchange(tm, j, j + 1);
      if (tm[j].h == tm[j + 1].h) {
        if (tm[j].m > tm[j + 1].m)
          exchange(tm, j, j + 1);
        if (tm[j].m == tm[j + 1].m)
          if (tm[j].s > tm[j + 1].s)
            exchange(tm, j, j + 1);
      }
    }
  }
  return 0;
}
int put_time(struct time tm[], int n) {
  for (int i = 0; i < n; i++)
    printf("%02d:%02d:%02d\n", tm[i].h, tm[i].m, tm[i].s);
  return 0;
}
int main() {
  struct time tm[100];
  int i, n;
  n = get_time(tm);
  sort_time(tm, n);
  put_time(tm, n);
}
