#include <cmath>
#include <iostream>
using namespace std;
class Point {
private:
  double x, y;

public:
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  double operator-(const Point &p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
  friend ostream &operator<<(ostream &os, const Point &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
  }
};
int main() {
  Point p1(10, 10);
  double x, y;
  while (cin >> x >> y) {
    Point p2(x, y);
    cout << p2 - p1 << endl;
  }
  return 0;
}
/*

Description

定义Point类，有2个double类型的属性表示点的横坐标和纵坐标。重载其减法运算符，用于计算两个点之间的距离。

Input

输入一系列点的坐标，每个点的坐标占一行。

Output

见样例。

Sample Input
20 20
30 30
40 40
50 50
Sample Output
14.1421
28.2843
42.4264
56.5685

HINT

Append Code
append.cc,
[Submit][Status]

*/