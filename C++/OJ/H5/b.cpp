#include <iostream>
using namespace std;
class Point {
private:
  static int cnt;
  int x, y;

public:
  Point(int x, int y) : x(x), y(y) {
    cout << "The Point (" << x << ", " << x << ") is created! Now, we have " << ++cnt << " points." << endl;
  }
  Point(const Point &other) : x(other.x), y(other.y) {
    cout << "A Point (" << x << ", " << y << ") is copied! Now, we have " << ++cnt << " points." << endl;
  }
  ~Point() {
    cout << "A Point (" << x << ", " << y << ") is erased! Now, we have " << --cnt << " points." << endl;
  }
  static int getNumOfPoints() {
    return cnt;
  }
  int getX() {
    return x;
  }
  int getY() {
    return y;
  }
};
int Point::cnt = 0;
class Circle {
private:
  static int cnt;
  Point center;
  int r;

public:
  Circle(int x, int y, int r) : center(x, y), r(r) {
    cout << "A circle at (" << x << ", " << y << ") and radius " << r << " is created! Now, we have " << ++cnt << " circles." << endl;
  }
  Circle(Point p, int r) : center(p), r(r) {
    cout << "A circle at (" << center.getX() << ", " << center.getY() << ") and radius " << r << " is created! Now, we have " << ++cnt << " circles." << endl;
  }
  ~Circle() {
    cout << "A circle at (" << center.getX() << ", " << center.getY() << ") and radius " << r << " is erased! Now, we have " << --cnt << " circles." << endl;
  }
  static int getNumOfCircles() {
    return cnt;
  }
  Point getCenter() {
    return center;
  }
  bool pointInCircle(Point &p) {
    return (p.getX() - center.getX()) * (p.getX() - center.getX()) + (p.getY() - center.getY()) * (p.getY() - center.getY()) < r * r;
  }
};
int Circle::cnt = 0;
int main() {
  int cases, num;
  int x, y, r, px, py;
  Point aPoint(0, 0), *bPoint;
  Circle aCircle(1, 1, 1);
  cin >> cases;
  cout << "We have " << Point::getNumOfPoints() << " points and " << Circle::getNumOfCircles() << " circles now." << endl;
  for (int i = 0; i < cases; i++) {
    cin >> x >> y >> r;
    bPoint = new Point(x, y);
    Circle circle(*bPoint, r);
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> px >> py;
      if (circle.pointInCircle(*(new Point(px, py)))) {
        cout << "(" << px << ", " << py << ") is in the circle at (";
        cout << circle.getCenter().getX() << ", " << circle.getCenter().getY() << ")." << endl;
      } else {
        cout << "(" << px << ", " << py << ") is not in the circle at (";
        cout << circle.getCenter().getX() << ", " << circle.getCenter().getY() << ")." << endl;
      }
    }
    delete bPoint;
  }
  cout << "We have " << Point::getNumOfPoints() << " points, and " << Circle::getNumOfCircles() << " circles." << endl;
  return 0;
}
