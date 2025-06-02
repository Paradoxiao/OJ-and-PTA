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
  Date date;
  Time time;

public:
  DateTime(int y = 1, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0) : date(y, m, d), time(h, min, s) {
    cout << "CREATE DateTime : (" << y << ", " << m << ", " << d << ", " << h << ", " << min << ", " << s << ")" << endl;
  }

  DateTime(Date d, Time t) : date(d), time(t) {}

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
  DateTime date_time;
  date_time.showDateTime();
  cout << endl;
  int cases;
  cin >> cases;
  for (int ca = 0; ca < cases; ca++) {
    int year, month, day;
    cin >> year >> month >> day;
    int hour, minute, second;
    cin >> hour >> minute >> second;
    date_time.setDateTime(year, month, day, hour, minute, second);
    date_time.showDateTime();
    cout << endl;
  }
}