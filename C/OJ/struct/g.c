#include <stdio.h>
#include <stdlib.h>
struct date {
  int y, m, d;
};
struct date to_date(char str[]) {
  /*int data = atoi(str);
  struct date temp;
  temp.y = data / 10000;
  data %= 10000;
  temp.m = data / 100;
  temp.d = data % 100;
  return temp;*/
  struct date temp;
  temp.y = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 +
           str[3] - '0';
  temp.m = (str[4] - '0') * 10 + str[5] - '0';
  temp.d = (str[6] - '0') * 10 + str[7] - '0';
  return temp;
}
int main() {
  char str[10];
  struct date dt;
  while (gets(str) != NULL) {
    dt = to_date(str);
    printf("%d %d %d\n", dt.y, dt.m, dt.d);
  }
  return 0;
}