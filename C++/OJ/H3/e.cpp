#include <iomanip>
#include <iostream>
using namespace std;
class Point {
  double a, b;

public:
  Point(double a = 0, double b = 0) : a(a), b(b) {}
  void show() {
    cout << setprecision(16);
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
  q.show();
}
