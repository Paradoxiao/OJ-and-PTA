#include <iostream>
using namespace std;
class Circle {
private:
  double r;

public:
  static double PI;
  Circle(double r) : r(r) {}
  double getRadius() const {
    return r;
  }
  double getArea() const {
    return PI * r * r;
  }
};
double Circle::PI = 3.14;
int main() {
  double radius;
  cout << "PI=" << Circle::PI << endl;
  const Circle c1(2);
  cout << "radius=" << c1.getRadius();
  cout << ",area=" << c1.getArea() << endl;
  cin >> radius;
  Circle c2(radius);
  cout << "radius=" << c2.getRadius();
  cout << ",area=" << c2.getArea() << endl;
  return 0;
}
