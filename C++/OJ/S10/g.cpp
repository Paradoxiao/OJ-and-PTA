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
  virtual ~Date() {
    cout << "destruct Date " << year << " " << month << " " << day << endl;
  }
  virtual void print() const = 0;
};
class BritishStyle : public Date {
private:
protected:
public:
  BritishStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct BritishStyle " << y << " " << m << " " << d << endl;
  }
  ~BritishStyle() {
    cout << "destruct BritishStyle " << year << " " << month << " " << day << endl;
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
    cout << "construct AmericanStyle " << y << " " << m << " " << d << endl;
  }
  ~AmericanStyle() {
    cout << "destruct AmericanStyle " << year << " " << month << " " << day << endl;
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
    cout << "construct GermanStyle " << y << " " << m << " " << d << endl;
  }
  ~GermanStyle() {
    cout << "destruct GermanStyle " << year << " " << month << " " << day << endl;
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
    cout << "construct SpanishStyle " << y << " " << m << " " << d << endl;
  }
  ~SpanishStyle() {
    cout << "destruct SpanishStyle " << year << " " << month << " " << day << endl;
  }
  void print() const {
    cout << day << "-" << month << "-" << year << endl;
  }
};
int main() {
  Date *date[100], *d;
  int year, month, day, cases = 0;
  while (cin >> year >> month >> day) {
    date[cases++] = new BritishStyle(year, month, day);
    date[cases++] = new AmericanStyle(year, month, day);
    date[cases++] = new GermanStyle(year, month, day);
    date[cases++] = new SpanishStyle(year, month, day);
  }
  for (int i = 0; i < cases; i++)
    date[i]->print();
  for (int i = 0; i < cases; i++)
    delete date[i];
}

/*

Description

日期类（Date）由年月日组成，在日常使用中英国、美国、德国、西班牙的日期输出格式均不相同。英国（BritishStyle类）的日期格式是“日/月/年”、美国（AmericanStyle类）的日期格式是“月-日-年”、德国（GermanStyle类）的日期格式是“年-月-日”、西班牙（SpanishStyle类）的日期格式是“日-月-年”。

         这里设计Date类用来存储年、月、日数据，BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类派生自Date类，用来改变输出格式。其中，print()函数是多态设计。

         用C++编写Date类、BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类来完成代码，调用格式见“Append Code”。

Date::print()、BritishStyle::print()、AmericanStyle::print()、GermanStyle::print()、SpanishStyle::print()按格式输出日期。

         Date类、BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类的构造函数、析构函数，根据题意设计。



Input

输入为多组。每组包括年、月、日三个整数。

Output

按格式输出日期。

Sample Input
2021 7 17
Sample Output
construct Date 2021 7 17
construct BritishStyle 2021 7 17
construct Date 2021 7 17
construct AmericanStyle 2021 7 17
construct Date 2021 7 17
construct GermanStyle 2021 7 17
construct Date 2021 7 17
construct SpanishStyle 2021 7 17
17/7/2021
7-17-2021
2021-7-17
17-7-2021
destruct BritishStyle 2021 7 17
destruct Date 2021 7 17
destruct AmericanStyle 2021 7 17
destruct Date 2021 7 17
destruct GermanStyle 2021 7 17
destruct Date 2021 7 17
destruct SpanishStyle 2021 7 17
destruct Date 2021 7 17
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
