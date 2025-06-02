#include <iostream>
using namespace std;
struct Point {
  double a, b;

  Point(double a, double b) : a(a), b(b) {
    cout << /* setprecision(16) <<*/ "Point : (" << a << ", " << b << ") is created." << endl;
  }
  Point() : a(0), b(0) {
    cout << /* setprecision(16) <<*/ "Point : (" << a << ", " << b << ") is created." << endl;
  }
  Point(double a) : a(a), b(a) {
    cout << /* setprecision(16) <<*/ "Point : (" << a << ", " << a << ") is created." << endl;
  }
  Point(const Point &p) {
    a = p.a;
    b = p.b;
    cout << /* setprecision(16) <<*/ "Point : (" << a << ", " << b << ") is copied." << endl;
  }
  ~Point() {
    cout << /* setprecision(16) <<*/ "Point : (" << a << ", " << b << ") is erased." << endl;
  }
  void show() {
    cout << "Point : (" << a << ", " << b << ")" << endl;
  }
  void showNoEndOfLine() const {
    cout << "Point : (" << a << ", " << b << ")";
  }
  double x() const {
    return a;
  }
  double y() const {
    return b;
  }
};
class Line {
private:
  Point p1, p2;

public:
  Line(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) : p1(x1, y1), p2(x2, y2) {
    cout << /* setprecision(16) <<*/ "Line : (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ") is created." << endl;
  }
  Line(const Point &p1, const Point &p2) : p1(p1), p2(p2) {
    cout << /* setprecision(16) <<*/ "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ") is created." << endl;
  }
  ~Line() {
    cout << /* setprecision(16) <<*/ "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ") is erased." << endl;
  }
  void readLine() {
    char _;
    cin >> p1.a >> _ >> p1.b >> p2.a >> _ >> p2.b;
  }
  void show() const {
    cout << "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ")" << endl;
  }
  Line(const Line &l) : p1(l.p1), p2(l.p2) {
    cout << /* setprecision(16) <<*/ "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ") is copied." << endl;
  }
  const Point &start() const {
    return p1;
  }
  const Point &end() const {
    return p2;
  }
  Line &setLine(double x1, double y1, double x2, double y2) {
    p1.a = x1;
    p1.b = y1;
    p2.a = x2;
    p2.b = y2;
    return *this;
  }
  Line &setLine(const Line &l) {
    p1.a = l.p1.a;
    p1.b = l.p1.b;
    p2.a = l.p2.a;
    p2.b = l.p2.b;
    return *this;
  }
  Line &setLine(Point &P1, Point &P2) {
    p1.a = P1.a;
    p1.b = P1.b;
    p2.a = P2.a;
    p2.b = P2.b;
    return *this;
  }
  void setStart(Point &p) {
    p1.a = p.a;
    p1.b = p.b;
  }
  void setEnd(Point &p) {
    p2.a = p.a;
    p2.b = p.b;
  }
};
void showLineCoordinate(const Line &line) {
  std::cout << "Line : ";
  std::cout << "(" << line.start().x() << ", " << line.start().y() << ")";
  std::cout << " to ";
  std::cout << "(" << line.end().x() << ", " << line.end().y() << ")";
  std::cout << std::endl;
}

void showLinePoint(const Line &line) {
  std::cout << "Line : ";
  line.start().showNoEndOfLine();
  std::cout << " to ";
  line.end().showNoEndOfLine();
  std::cout << std::endl;
}

void showLine(const Line &line) {
  line.show();
}

int main() {
  int num, i;
  Point p(1, -2), q(2, -1), t;
  t.show();
  std::cin >> num;
  Line line[num + 1];
  for (i = 1; i <= num; i++) {
    line[i].readLine();
    showLine(line[i]);
  }
  Line l1(p, q), l2(p, t), l3(q, t), l4(l1);
  showLineCoordinate(l1);
  showLinePoint(l2);
  showLinePoint(l3.setLine(l1));
  showLineCoordinate(l4.setLine(t, q));
  line[0].setStart(t);
  line[0].setEnd(q);
}