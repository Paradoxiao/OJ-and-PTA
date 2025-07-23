#include <stdio.h>

struct time {
  int hour;
  int minute;
  int second;
};

int get_time(struct time tm[]);
void sort_time(struct time tm[], int n);
int put_time(struct time tm[], int n);

int main() {
  struct time tm[100];
  int i, n;
  n = get_time(tm);
  sort_time(tm, n);
  put_time(tm, n);
  return 0;
}

int get_time(struct time tm[]) {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &tm[i].hour, &tm[i].minute, &tm[i].second);
  }
  return n;
}

void sort_time(struct time tm[], int n) {
  int i, j;
  struct time temp;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if ((tm[i].hour > tm[j].hour) ||
          (tm[i].hour == tm[j].hour && tm[i].minute > tm[j].minute) ||
          (tm[i].hour == tm[j].hour && tm[i].minute == tm[j].minute &&
           tm[i].second > tm[j].second)) {
        temp = tm[i];
        tm[i] = tm[j];
        tm[j] = temp;
      }
    }
  }
}

int put_time(struct time tm[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%02d:%02d:%02d\n", tm[i].hour, tm[i].minute, tm[i].second);
  }
  return 0;
}