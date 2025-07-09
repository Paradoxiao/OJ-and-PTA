#include <iostream>
using namespace std;
class Date {
private:
protected:
  int year, month, day;

public:
  Date(int y, int m, int d) : year(y), month(m), day(d) {
    cout << "construct Date " << year << " " << month << " " << day << endl;
  }
  void print() const {
    cout << year << "-" << month << "-" << day << endl;
  }
};
class BritishStyle : public Date {
private:
protected:
public:
  BritishStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct BritishStyle " << year << " " << month << " " << day << endl;
  }
  void print() const {
    cout << day << "/" << month << "/" << year << endl;
  }
};
class AmericanStyle : public Date {
private:
protected:
public:
  AmericanStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct AmericanStyle " << year << " " << month << " " << day << endl;
  }
  void print() const {
    cout << month << "-" << day << "-" << year << endl;
  }
};
class GermanStyle : public Date {
private:
protected:
public:
  GermanStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct GermanStyle " << year << " " << month << " " << day << endl;
  }
  void print() const {
    cout << year << "-" << month << "-" << day << endl;
  }
};
class SpanishStyle : public Date {
private:
protected:
public:
  SpanishStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct SpanishStyle " << year << " " << month << " " << day << endl;
  }
  void print() const {
    cout << day << "-" << month << "-" << year << endl;
  }
};
int main() {
  int year, month, day;
  while (cin >> year >> month >> day) {
    BritishStyle british(year, month, day);
    british.Date::print();
    british.print();
    AmericanStyle american(year, month, day);
    american.Date::print();
    american.print();
    GermanStyle german(year, month, day);
    german.Date::print();
    german.print();
    SpanishStyle spanish(year, month, day);
    spanish.Date::print();
    spanish.print();
  }
}

/*

Description

日期类（Date）由年月日组成，在日常使用中英国、美国、德国、西班牙的日期输出格式均不相同。英国（BritishStyle类）的日期格式是“日/月/年”、美国（AmericanStyle类）的日期格式是“月-日-年”、德国（GermanStyle类）的日期格式是“年-月-日”、西班牙（SpanishStyle类）的日期格式是“日-月-年”。

         这里设计Date类用来存储年、月、日数据，BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类派生自Date类，用来改变输出格式。

         用C++编写Date类、BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类来完成代码，调用格式见“Append Code”。

Date::print()、BritishStyle::print()、AmericanStyle::print()、GermanStyle::print()、SpanishStyle::print()按格式输出日期。

         Date类、BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类的构造函数，根据题意设计。

Input

输入为多组。每组包括年、月、日三个整数。

Output

按格式输出日期。

Sample Input
2021 7 17
Sample Output
construct Date 2021 7 17
construct BritishStyle 2021 7 17
2021-7-17
17/7/2021
construct Date 2021 7 17
construct AmericanStyle 2021 7 17
2021-7-17
7-17-2021
construct Date 2021 7 17
construct GermanStyle 2021 7 17
2021-7-17
2021-7-17
construct Date 2021 7 17
construct SpanishStyle 2021 7 17
2021-7-17
17-7-2021
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
