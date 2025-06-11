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