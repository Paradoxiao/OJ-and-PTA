#include <iostream>
using namespace std;
class Time {
private:
  int hh, mm, ss;

public:
  operator int() {
    return hh * 3600 + mm * 60 + ss;
  }
  friend istream &operator>>(istream &in, Time &t) {
    in >> t.hh >> t.mm >> t.ss;
    return in;
  }
  friend ostream &operator<<(ostream &out, const Time &t) {
    out << t.hh << ":" << t.mm << ":" << t.ss;
    return out;
  }
  int operator-(const Time &t) const {
    int total_seconds = (hh * 3600 + mm * 60 + ss) - (t.hh * 3600 + t.mm * 60 + t.ss);
    if (total_seconds < 0)
      total_seconds = -total_seconds;
    Time result;
    result.hh = total_seconds / 3600;
    total_seconds %= 3600;
    result.mm = total_seconds / 60;
    result.ss = total_seconds % 60;
    return (int)result;
  }
  int operator[](int index) const {
    switch (index) {
    case 0:
      return ss;
    case 1:
      return mm;
    case 2:
      return hh;
    }
    return -1;
  }
};
int main() {
  Time a, b;
  int index;
  cin >> a >> b >> index;
  cout << int(a) << " " << int(b) << endl;
  cout << a << ";";
  cout << b << endl;
  cout << b - a << endl;
  cout << a[index] << endl;
  return 0;
}

/*

Description

输入同一天内的两个时间，求它们之间间隔多少秒。编写Time类，包括：

1.重载输入、输出运算符。其中输入运算符按照指定格式输入时间；输出运算符使用“:”分割小时、分钟、秒来输出时间。

2.重载强制类型转换运算符int，将时间转换为距离当天0点0分0秒的秒数。

3.重载减法运算符，求两个时间之间间隔的秒数（非负整数）。

4.重载下标运算符，对于给定的下标值0,1,2，分别返回时间的秒值、分钟值、小时值。假定给定的下标是合法的。
Input

输入有2行，每行是一个时间，格式为“hh mm ss”。
Output

见样例。
Sample Input
0 0 0
1 1 1
2
Sample Output
0 3661
0:0:0;1:1:1
3661
0
HINT

*/
