#include <iomanip>
#include <iostream>
using namespace std;
class Date {
private:
  int Year, Month, Day;

public:
  Date(int y, int m, int d) : Year(y), Month(m), Day(d) {}

  void showDate() {
    cout << setw(4) << setfill('0') << Year << "-" << setw(2) << setfill('0') << Month << "-" << setw(2) << setfill('0') << Day;
  }
};
class Time {
private:
  int Hour, Minute, Second;

public:
  Time(int h, int m, int s) : Hour(h), Minute(m), Second(s) {}

  void showTime() {
    cout << setw(2) << setfill('0') << Hour << ":" << setw(2) << setfill('0') << Minute << ":" << setw(2) << setfill('0') << Second;
  }
};
class DateTime {
private:
  Date date;
  Time time;

public:
  DateTime(int y, int m, int d, int h, int min, int s) : date(y, m, d), time(h, min, s) {}

  DateTime(Date d, Time t) : date(d), time(t) {}

  void showDateTime() {
    date.showDate();
    cout << " ";
    time.showTime();
  }

  DateTime &setDateTime(int y, int m, int d, int h, int min, int s) {
    date = Date(y, m, d);
    time = Time(h, min, s);
    return *this;
  }
};
int main() {
  Date date(1000, 10, 10);
  Time time(1, 1, 1);
  DateTime date_time(date, time);
  date_time.showDateTime();
  cout << endl;
  int cases, flag = 0;
  cin >> cases;
  for (int ca = 0; ca < cases; ca++) {
    int year, month, day;
    cin >> year >> month >> day;
    int hour, minute, second;
    cin >> hour >> minute >> second;
    if (flag == 0) {
      flag = 1;
      DateTime dt(year, month, day, hour, minute, second);
      dt.showDateTime();
    } else if (flag == 1) {
      flag == 0;
      date_time.setDateTime(year, month, day, hour, minute, second).showDateTime();
    }
    cout << endl;
  }
}

/*

Description

设计一个日期时间类，用于读取输入的数据，按格式输出日期和时间。

设计日期时间类DateTime由2个成员组成，分别是一个Date类对象和一个Time类对象；

设计DateTime类需支持以下操作：

DateTime::DateTime()无参构造方法：初始化为1年1月1日、0时0分0秒；

DateTime::DateTime(const Date&,const Time&)构造方法：依照参数传入的日期和时间初始化对象；

DateTime::DateTime(int,int,int,int,int,int)构造方法：依照参数（顺序为年月日、时分秒）初始化对象；

DateTime::showDateTime()方法：按格式输出DateTime对象；

DateTime::setDateTime(int,int,int,int,int,int)方法：依照参数（顺序为年月日、时分秒）修改对象的属性值；

DateTime类包含了两个类：Date类和Time类

设计日期类Date需支持以下操作：

Date::Date()无参构造方法：初始化为1年1月1日

Date::Date(int,int,int)构造方法：传入的参数依次为年月日，用参数将日期初始化。

Date::showDate()方法：按格式输出Date对象。

Date::setDate(int,int,int)方法：传入的参数依次为年月日，用参数修改对象的属性值

设计时间类Time需支持以下操作：

Time::Time()无参构造方法：初始化为0时0分0秒

Time::Time(int,int,int)构造方法：传入的参数依次为时分秒，用参数将时间初始化。

Time::showTime()方法：按格式输出Time对象。

Time::setTime(int,int,int)方法：传入的参数依次为时分秒，用参数修改对象的属性值

-----------------------------------------------------------------------------

你设计DateTime类、Date类和Time类，使得main()函数能够正确运行。

函数调用格式见append.cc。

append.cc中已给出main()函数。

Input

输入的第一个整数n，表示有n组测试数据。

后面的输入每行为一组测试数据。每组测试数据的前3个整数是日期的年月日，后3个整数是时间的时分秒。

Output
每组测试数据对应一行输出。日期的输出格式为“yyyy-mm-dd”，时间的输出格式为“hh:mm:ss”，中间用一个空格分开。

Sample Input
3
1982 10 1 0 0 0
2000 2 28 23 59 59
2014 7 2 13 30 01
Sample Output
1000-10-10 01:01:01
1982-10-01 00:00:00
2000-02-28 23:59:59
2014-07-02 13:30:01
HINT

输出格式用头文件<iomanip>中流操作算子：

setw(w)   ：设置数据的输出宽度为w个字符

setfill(c)：设置用字符c作为填充字符

Append Code
append.cc,
[Submit][Status]

*/