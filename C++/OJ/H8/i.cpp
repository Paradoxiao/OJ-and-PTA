#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int year, month;
  while (cin >> year >> month) {
    int j, days, m, h;
    if (month == 2)
      days = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
      days = 30;
    else
      days = 31;
    year -= month < 3, m = month < 3 ? month + 12 : month;
    h = (13 * (m + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    cout << "Sun Mon Tue Wen Thu Fri Sat" << endl;
    for (j = 0; j < h; j++)
      cout << (j ? " " : "") << "   ";
    for (int i = 1; i <= days; i++, j++)
      cout << (j != 0 && j % 7 == 0 ? "\n" : "") << (j % 7 ? " " : "") << setw(3) << i;
    cout << endl << endl;
  }
  return 0;
}
/*

Description

输出公元1900～2200年之间任意一月的月历。

Input

输入若干行，至EOF结束，每行两个整数，分别表示年和月。

Output

对应输入顺序输出月历，两个月历之间有一个空行。
每个月历的第一行为表头"Sun Mon Tue Wen Thu Fri
Sat"，表示星期日～星期六。第二行开始的每行为一个星期，把每月的1日～结尾一日对应阿拉伯数字填入其中。每列占3个字符，其中的数字右对齐，每两列之间一个空格分隔，每行最后一个数字后面不要有空格。最后一日后面不要有空格。

Sample Input
2019 11
2019 12
2020 1
2020 2
Sample Output
Sun Mon Tue Wen Thu Fri Sat
                      1   2
  3   4   5   6   7   8   9
 10  11  12  13  14  15  16
 17  18  19  20  21  22  23
 24  25  26  27  28  29  30

Sun Mon Tue Wen Thu Fri Sat
  1   2   3   4   5   6   7
  8   9  10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28
 29  30  31

Sun Mon Tue Wen Thu Fri Sat
              1   2   3   4
  5   6   7   8   9  10  11
 12  13  14  15  16  17  18
 19  20  21  22  23  24  25
 26  27  28  29  30  31

Sun Mon Tue Wen Thu Fri Sat
                          1
  2   3   4   5   6   7   8
  9  10  11  12  13  14  15
 16  17  18  19  20  21  22
 23  24  25  26  27  28  29
HINT

Append Code
[Submit][Status]

*/
