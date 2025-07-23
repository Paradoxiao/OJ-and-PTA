// Description
// 对一个合法的日期，输出它是星期几的英文名称。

//          1、星期一：Monday

//          2、星期二：Tuesday

//          3、星期三：Wednesday

//          4、星期四：Thursday

//          5、星期五：Friday

//          6、星期六：Saturday

//          7、星期日：Sunday

// Input
// 输入为多组数据至EOF结束，每个文件最多不超过50个测试样例。每组输入三个整数表示日期的年月日，其中年份在1800-2400之间。输入的数据均为合法日期。

// Output
// 输出该日期是星期几。

// Sample Input
// 2025 1 10
// 2025 3 30
// Sample Output
// Friday
// Sunday
// HINT
#include <stdio.h>

int day_of_week(int y, int m, int d) {
  if (m < 3) {
    m += 12;
    y -= 1;
  }
  return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

const char *get_weekday_name(int day) {
  const char *names[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"};
  return names[day];
}

int main() {
  int y, m, d;
  while (scanf("%d %d %d", &y, &m, &d) != EOF) {
    int day = day_of_week(y, m, d);
    printf("%s\n", get_weekday_name(day));
  }
  return 0;
}