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