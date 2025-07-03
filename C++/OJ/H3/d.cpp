#include <iomanip>
#include <iostream>
using namespace std;
class Date {
private:
  int Year, Month, Day;

public:
  Date(int y, int m, int d) : Year(y), Month(m), Day(d) {
    cout << "CREATE Date : (" << Year << ", " << Month << ", " << Day << ")" << endl;
  }
  Date(const Date &d) {
    Year = d.Year;
    Month = d.Month;
    Day = d.Day;
    cout << "COPY   Date : (" << Year << ", " << Month << ", " << Day << ")" << endl;
  }
  int year() const {
    return Year;
  }
  int month() const {
    return Month;
  }
  int day() const {
    return Day;
  }
  void year(int y) {
    Year = y;
  }
  void month(int m) {
    Month = m;
  }
  void day(int d) {
    Day = d;
  }
  void setDate(int y, int m, int d) {
    Year = y;
    Month = m;
    Day = d;
  }
  void showCreate() {
    cout << "CREATE Date : (" << Year << ", " << Month << ", " << Day << ")" << endl;
  }
  void showDate() {
    cout << setw(4) << setfill('0') << Year << "-" << setw(2) << setfill('0') << Month << "-" << setw(2) << setfill('0') << Day;
  }
};
class Time {
private:
  int Hour, Minute, Second;

public:
  Time(int h, int m, int s) : Hour(h), Minute(m), Second(s) {
    cout << "CREATE Time : (" << Hour << ", " << Minute << ", " << Second << ")" << endl;
  }
  Time(const Time &t) {
    Hour = t.Hour;
    Minute = t.Minute;
    Second = t.Second;
    cout << "COPY   Time : (" << Hour << ", " << Minute << ", " << Second << ")" << endl;
  }
  int hour() const {
    return Hour;
  }
  int minute() const {
    return Minute;
  }
  int second() const {
    return Second;
  }
  void hour(int h) {
    Hour = h;
  }
  void minute(int m) {
    Minute = m;
  }
  void second(int s) {
    Second = s;
  }
  void setTime(int h, int m, int s) {
    Hour = h;
    Minute = m;
    Second = s;
  }
  void showCreate() {
    cout << "CREATE Time : (" << Hour << ", " << Minute << ", " << Second << ")" << endl;
  }
  void showTime() {
    cout << setw(2) << setfill('0') << Hour << ":" << setw(2) << setfill('0') << Minute << ":" << setw(2) << setfill('0') << Second;
  }
};
class DateTime {
private:
  Time time;
  Date date;

public:
  DateTime(int y = 1, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0) : time(h, min, s), date(y, m, d) {
    cout << "CREATE DateTime : (" << y << ", " << m << ", " << d << ", " << h << ", " << min << ", " << s << ")" << endl;
  }
  DateTime(const Date &d, const Time &t) : time(t), date(d) {
    cout << "CREATE DateTime : (" << date.year() << ", " << date.month() << ", " << date.day() << ") (" << time.hour() << ", " << time.minute() << ", " << time.second() << ")" << endl;
  }
  DateTime(const DateTime &dt) : time(dt.time), date(dt.date) {
    cout << "COPY   DateTime : (" << date.year() << ", " << date.month() << ", " << date.day() << ") (" << time.hour() << ", " << time.minute() << ", " << time.second() << ")" << endl;
  }
  int year() const {
    return date.year();
  }
  int month() const {
    return date.month();
  }
  int day() const {
    return date.day();
  }
  int hour() const {
    return time.hour();
  }
  int minute() const {
    return time.minute();
  }
  int second() const {
    return time.second();
  }
  void year(int y) {
    date.year(y);
  }
  void month(int m) {
    date.month(m);
  }
  void day(int d) {
    date.day(d);
  }
  void hour(int h) {
    time.hour(h);
  }
  void minute(int m) {
    time.minute(m);
  }
  void second(int s) {
    time.second(s);
  }
  void showDateTime() {
    date.showDate();
    cout << " ";
    time.showTime();
  }

  DateTime &setDateTime(int y, int m, int d, int h, int min, int s) {
    date.setDate(y, m, d);
    time.setTime(h, min, s);
    return *this;
  }
};
int main() {
  const Date date(1000, 10, 10), dt(date);
  const Time time(1, 1, 1), tm(time);
  DateTime date_time(dt, tm);
  const DateTime cnt(date_time);
  cout << "DateTime : " << cnt.year() << " " << cnt.month() << " " << cnt.day();
  cout << " " << cnt.hour() << " " << cnt.minute() << " " << cnt.second();
  cout << endl;
  int cases;
  cin >> cases;
  for (int ca = 0; ca < cases; ca++) {
    int year, month, day;
    cin >> year >> month >> day;
    int hour, minute, second;
    cin >> hour >> minute >> second;
    date_time.year(year);
    date_time.month(month);
    date_time.day(day);
    date_time.hour(hour);
    date_time.minute(minute);
    date_time.second(second);
    date_time.showDateTime();
    cout << endl;
  }
}
/*

Description

设计一个日期时间类，用于读取输入的数据，按格式输出日期和时间。

设计日期时间类DateTime由2个成员组成，分别是一个Date类对象和一个Time类对象；

设计DateTime类需支持以下操作：

DateTime::DateTime()无参构造方法：初始化为1年1月1日、0时0分0秒；

DateTime::DateTime(int,int,int,int,int,int)构造方法：依照参数（顺序为年月日、时分秒）初始化对象；

在上述两个DateTime类的构造函数中输出：“CREATE DateTime : (y, m, d, hh, mm, ss)”，其中y、m、d为初始化对象时的年月日值，h、m、s为初始化对象时的时分秒值。参见输出。

DateTime::DateTime(const Date&,const Time&)构造方法：依照参数传入的日期和时间初始化对象；

在这个DateTime类的构造函数中输出：“CREATE DateTime : (y, m, d) (hh, mm, ss)”，其中y、m、d为初始化对象时的年月日值，h、m、s为初始化对象时的时分秒值。参见输出。

DateTime:DateTime(const DateTime&)构造方法：拷贝构造函数，初始化对象。

在拷贝构造函数中输出：“COPY   DateTime : (y, m, d) (hh, mm, ss)”，其中y、m、d为初始化对象时的年月日值，h、m、s为初始化对象时的时分秒值。参见输出。

DateTime::showDateTime()方法：按格式输出DateTime对象；

DateTime::setDateTime(int,int,int,int,int,int)方法：依照参数（顺序为年月日、时分秒）修改对象的属性值；

编写DateTime类的读写函数：year()、month()、day()、hour()、minute()、second()。读写函数的参数、返回值参见main()函数。

DateTime类包含了两个类：Date类和Time类

设计日期类Date需支持以下操作：

Date::Date()无参构造方法：初始化为1年1月1日

Date::Date(int,int,int)构造方法：传入的参数依次为年月日，用参数将日期初始化。

在Date类的构造函数中输出：“CREATE Date : (y, m, d)”，其中y、m、d为初始化对象时的年月日值。参见输出。

Date::Date(const Date&)构造方法：拷贝构造函数，初始化对象。

在拷贝构造函数中输出：“COPY   Date : (y, m, d)”，其中y、m、d为初始化对象时的年月日值。参见输出。

Date::showDate()方法：按格式输出Date对象。

Date::setDate(int,int,int)方法：传入的参数依次为年月日，用参数修改对象的属性值

设计时间类Time需支持以下操作：

Time::Time()无参构造方法：初始化为0时0分0秒

Time::Time(int,int,int)构造方法：传入的参数依次为时分秒，用参数将时间初始化。

在Time类的构造函数中输出：“CREATE Time : (h, m, s)”，其中h、m、s为初始化对象时的时分秒值。参见输出

Time::Time(const Time&)构造方法：拷贝构造函数，初始化对象。

在拷贝构造函数中输出：“COPY   Time : (h, m, s)”，其中h、m、s为初始化对象时的时分秒值。参见输出

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
CREATE Date : (1000, 10, 10)
COPY   Date : (1000, 10, 10)
CREATE Time : (1, 1, 1)
COPY   Time : (1, 1, 1)
COPY   Time : (1, 1, 1)
COPY   Date : (1000, 10, 10)
CREATE DateTime : (1000, 10, 10) (1, 1, 1)
COPY   Time : (1, 1, 1)
COPY   Date : (1000, 10, 10)
COPY   DateTime : (1000, 10, 10) (1, 1, 1)
DateTime : 1000 10 10 1 1 1
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