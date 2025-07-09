#include <iostream>
using namespace std;
class Date {
private:
  int y, m, d;

protected:
public:
  void year(int year) {
    y = year;
  }
  void month(int month) {
    m = month;
  }
  void day(int day) {
    d = day;
  }
  void print() const {
    cout << y << "-" << m << "-" << d << endl;
  }
};
int main() {
  Date date;
  int year, month, day;
  while (cin >> year >> month >> day) {
    date.year(year);
    date.month(month);
    date.day(day);
    date.print();
  }
}

/*

Description

用C++编写Date类来完成代码，调用格式见“Append Code”。

Date::year(int)写入年；

Date::month(int)写入月；

Date::day(int)写入日；

Date::print()按格式输出日期。

Input

         输入为多组。每组包括年、月、日三个整数。

Output

         按格式输出日期。

Sample Input
2000 1 1
2021 7 17
Sample Output
2000-1-1
2021-7-17
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
