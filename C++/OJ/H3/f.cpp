#include <iomanip>
#include <iostream>
using namespace std;
class Point {
  double a, b;

public:
  Point(double a, double b) : a(a), b(b) {
    cout << setprecision(16) << "Point : (" << a << ", " << b << ") is created." << endl;
  }
  Point() : a(0), b(0) {
    cout << setprecision(16) << "Point : (" << a << ", " << b << ") is created." << endl;
  }
  Point(double a) : a(a), b(a) {
    cout << setprecision(16) << "Point : (" << a << ", " << a << ") is created." << endl;
  }
  Point(const Point &p) {
    a = p.a;
    b = p.b;
    cout << setprecision(16) << "Point : (" << a << ", " << b << ") is copied." << endl;
  }
  ~Point() {
    cout << setprecision(16) << "Point : (" << a << ", " << b << ") is erased." << endl;
  }
  void show() {
    cout << "Point : (" << a << ", " << b << ")" << endl;
  }
};
int main() {
  char c;
  double a, b;
  Point q;
  while (std::cin >> a >> c >> b) {
    Point p(a, b);
    p.show();
  }
  Point q1(q), q2(1);
  q1.show();
  q2.show();
  q.show();
}
