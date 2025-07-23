#include <stdio.h>
int main() {
  int time, h, m, s;
  for (;;) {
    scanf("%d", &time);
    if (time == 0)
      break;
    time--;
    h = time / 3600;
    time %= 3600;
    m = time / 60;
    s = time % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
  }
  return 0;
}