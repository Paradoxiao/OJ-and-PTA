#include <iomanip>
#include <iostream>
using namespace std;
class Time {
private:
  int h, m, s;

public:
  int hour() {
    return h;
  }
  void hour(int hour) {
    h = hour;
  }
  int minute() {
    return m;
  }
  void minute(int minute) {
    m = minute;
  }
  int second() {
    return s;
  }
  void second(int second) {
    s = second;
  }
};
int main() {
  Time t;
  int cases;
  cin >> cases;
  for (int i = 1; i <= cases; ++i) {
    int hour, minute, second;
    cin >> hour >> minute >> second;
    t.hour(hour);
    t.minute(minute);
    t.second(second);
    cout << setw(2) << setfill('0') << t.hour() << ":";
    cout << setw(2) << setfill('0') << t.minute() << ":";
    cout << setw(2) << setfill('0') << t.second() << endl;
  }
}
