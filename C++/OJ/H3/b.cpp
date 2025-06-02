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
