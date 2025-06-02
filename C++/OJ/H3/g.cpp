#include <iomanip>
#include <iostream>
using namespace std;
struct Point {
  double a, b;

  Point(double a, double b) : a(a), b(b) {
    cout << "Point : (" << a << ", " << b << ") is created." << endl;
  }
  Point() : a(0), b(0) {
    cout << "Point : (" << a << ", " << b << ") is created." << endl;
  }
  Point(double a) : a(a), b(a) {
    cout << "Point : (" << a << ", " << a << ") is created." << endl;
  }
  Point(const Point &p) {
    a = p.a;
    b = p.b;
    cout << "Point : (" << a << ", " << b << ") is copied." << endl;
  }
  ~Point() {
    cout << "Point : (" << a << ", " << b << ") is erased." << endl;
  }
  void show() {
    cout << "Point : (" << a << ", " << b << ")" << endl;
  }
};
class Line {
private:
  Point p1, p2;

public:
  Line(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2) {
    cout << "Line : (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ") is created." << endl;
  }
  Line(const Point &p1, const Point &p2) : p1(p1), p2(p2) {
    cout << "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ") is created." << endl;
  }
  ~Line() {
    cout << "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ") is erased." << endl;
  }
  void show() {
    cout << "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ")" << endl;
  }
  Line(const Line &l) : p1(l.p1), p2(l.p2) {
    cout << "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ") is copied." << endl;
  }
};
int main() {
  char c;
  int num, i;
  double x1, x2, y1, y2;
  Point p(1, -2), q(2, -1), t;
  t.show();
  std::cin >> num;
  for (i = 1; i <= num; i++) {
    std::cout << "=========================\n";
    std::cin >> x1 >> c >> y1 >> x2 >> c >> y2;
    Line line(x1, y1, x2, y2);
    line.show();
  }
  std::cout << "=========================\n";
  Line l1(p, q), l2(p, t), l3(q, t), l4(t, q);
  l1.show();
  l2.show();
  l3.show();
  l4.show();
}
