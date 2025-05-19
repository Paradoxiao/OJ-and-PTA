#include <cstdio>
int main() {
  int y, m, d;
  const char *names[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"};
  while (scanf("%d %d %d", &y, &m, &d) != EOF) {
    if (m < 3) {
      m += 12;
      y -= 1;
    }
    int day = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    printf("%s\n", names[day]);
  }
  return 0;
}