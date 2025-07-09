#include <iostream>
using namespace std;
class Date {
private:
  int y, m, d;

protected:
public:
  Date(int year, int month, int day) : y(year), m(month), d(day) {}
  void print() const {
    cout << y << "-" << m << "-" << d << endl;
  }
  int year() const {
    return y;
  }
  int month() const {
    return m;
  }
  int day() const {
    return d;
  }
};
int main() {
  int year, month, day;
  while (cin >> year >> month >> day) {
    const Date date(year, month, day);
    date.print();
    cout << date.year() << "/" << date.month() << "/" << date.day() << endl;
  }
}

/*

Description

用C++编写Date类来完成代码，调用格式见“Append Code”。

Date::print()按格式输出日期。

         Date类的构造函数，根据题意设计。

Input

输入为多组。每组包括年、月、日三个整数。

Output

按格式输出日期。

Sample Input
2000 1 1
2021 7 17
Sample Output
2000-1-1
2000/1/1
2021-7-17
2021/7/17
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
