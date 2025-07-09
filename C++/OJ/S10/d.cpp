#include <iostream>
using namespace std;
class Date {
private:
  int year, month, day;

protected:
public:
  Date(int y = 1000, int m = 1, int d = 1) : year(y), month(m), day(d) {}
  Date(const Date &d) : year(d.year), month(d.month), day(d.day) {}
  Date &operator=(const Date &d) {
    if (this != &d) {
      year = d.year;
      month = d.month;
      day = d.day;
    }
    return *this;
  }
  void print() const {
    cout << year << "-" << month << "-" << day << endl;
  }
};
int main() {
  Date date, dd;
  dd.print();
  int year, month, day;
  while (cin >> year >> month >> day) {
    Date d(year, month, day);
    date = dd = d;
    date.print();
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
1000-1-1
2000-1-1
2021-7-17
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
