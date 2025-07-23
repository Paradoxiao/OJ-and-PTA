#include <stdio.h>
struct clock {
  long long h, m, s;
};
int get_clock(struct clock *tm, int *change) {
  return scanf("%lld:%lld:%lld %d", &tm->h, &tm->m, &tm->s, change);
}
void put_clock(struct clock tm) {
  printf("%02lld:%02lld:%02lld\n", tm.h, tm.m, tm.s);
}
struct clock turn_clock(struct clock tm, int change) {
  tm.s += change;
  if (tm.s >= 60) {
    tm.m += tm.s / 60;
    tm.s %= 60;
  }
  if (tm.s < 0) {
    tm.m += (tm.s / 60) - 1;
    tm.s = 60 + (tm.s % 60);
    if (tm.s == 60) {
      tm.s = 0;
      tm.m += 1;
    }
  }
  if (tm.m >= 60) {
    tm.h += tm.m / 60;
    tm.m %= 60;
  }
  if (tm.m < 0) {
    tm.h += (tm.m / 60) - 1;
    tm.m = 60 + (tm.m % 60);
    if (tm.m == 60) {
      tm.m = 0;
      tm.h += 1;
    }
  }
  if (tm.h >= 24) {
    tm.h %= 24;
  }
  if (tm.h < 0) {
    tm.h = 24 + (tm.h % 24);
    if (tm.h == 24) {
      tm.h = 0;
    }
  }
  return tm;
}
int main() {
  int n;
  struct clock ck;
  while (get_clock(&ck, &n) != EOF)
    put_clock(turn_clock(ck, n));
  return 0;
}