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
int main() {
  int cases;
  cin >> cases;
  for (int ca = 0; ca < cases; ca++) {
    int year, month, day;
    cin >> year >> month >> day;
    Date date(year, month, day);
    date.showDate();
    cout << " ";
    int hour, minute, second;
    cin >> hour >> minute >> second;
    Time time(hour, minute, second);
    time.showTime();
    cout << endl;
  }
}
