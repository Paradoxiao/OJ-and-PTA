#include <iostream>
using namespace std;
struct Point {
  double a, b;
  static int n, sum;
  Point(double a, double b) : a(a), b(b) {
    n++, sum++;
  }
  Point() : a(0), b(0) {
    n++, sum++;
  }
  Point(double a) : a(a), b(a) {
    n++, sum++;
  }
  Point(const Point &p) {
    a = p.a;
    b = p.b;
    n++, sum++;
  }
  ~Point() {
    n--;
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
  static void showCounter() {
    cout << "Current : " << n << " points." << endl;
  }
  static void showSum() {
    cout << "In total : " << sum << " points." << endl;
  }
};
int Point::n = 0, Point::sum = 0;
class Line {
private:
  Point p1, p2;
  static int n, sum;

public:
  Line(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) : p1(x1, y1), p2(x2, y2) {
    n++, sum++;
  }
  Line(const Point &p1, const Point &p2) : p1(p1), p2(p2) {
    n++, sum++;
  }
  Line(const Line &l) : p1(l.p1), p2(l.p2) {
    n++, sum++;
  }
  ~Line() {
    n--;
  }
  void readLine() {
    char _;
    cin >> p1.a >> _ >> p1.b >> p2.a >> _ >> p2.b;
  }
  void show() const {
    cout << "Line : (" << p1.a << ", " << p1.b << ") to (" << p2.a << ", " << p2.b << ")" << endl;
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
  static void showCounter() {
    cout << "Current : " << n << " lines." << endl;
  }
  static void showSum() {
    cout << "In total : " << sum << " lines." << endl;
  }
};
int Line::n = 0, Line::sum = 0;

int main() {
  int num, i;
  Point p(1, -2), q(2, -1), t;
  t.showCounter();
  t.showSum();
  std::cin >> num;
  Line line[num + 1];
  for (i = 1; i <= num; i++) {
    Line *l1, l2;
    l1->showCounter();
    l1->showSum();
    l1 = new Line(p, q);
    line[i].readLine();
    p.showCounter();
    p.showSum();
    delete l1;
    l2.showCounter();
    l2.showSum();
    q.showCounter();
    q.showSum();
  }
  Line l1(p, q), l2(p, t), l3(q, t), l4(l1);
  Line::showCounter();
  Line::showSum();
  Point::showCounter();
  Point::showSum();
  Line *l = new Line[num];
  l4.showCounter();
  l4.showSum();
  delete[] l;
  t.showCounter();
  t.showSum();
}
/*

Description
在数学上，平面直角坐标系上的点用X轴和Y轴上的两个坐标值唯一确定，两点确定一条线段。现在我们封装一个“Point类”和“Line类”来实现平面上的点的操作。
根据“append.cc”，完成Point类和Line类的构造方法和show()方法，输出各Line对象和Point对象的构造和析构次序。
接口描述：
Point::showCounter()方法：按格式输出当前程序中Point对象的计数。
Point::showSum()方法：按格式输出程序运行至当前存在过的Point对象总数。
Line::showCounter()方法：按格式输出当前程序中Line对象的计数。
Line::showSum()方法：按格式输出程序运行至当前存在过的Line对象总数。

Input
输入的第一行为N，表示后面有N行测试样例。
每行为两组坐标“x,y”，分别表示线段起点和终点的x坐标和y坐标，两组坐标间用一个空格分开，x和y的值都在double数据范围内。

Output
输出格式见sample。
C语言的输入输出被禁用。

Sample Input
4
0,0 1,1
1,1 2,3
2,3 4,5
0,1 1,0
Sample Output
Current : 3 points.
In total : 3 points.
Current : 6 lines.
In total : 6 lines.
Current : 17 points.
In total : 17 points.
Current : 6 lines.
In total : 7 lines.
Current : 15 points.
In total : 17 points.
Current : 6 lines.
In total : 8 lines.
Current : 17 points.
In total : 21 points.
Current : 6 lines.
In total : 9 lines.
Current : 15 points.
In total : 21 points.
Current : 6 lines.
In total : 10 lines.
Current : 17 points.
In total : 25 points.
Current : 6 lines.
In total : 11 lines.
Current : 15 points.
In total : 25 points.
Current : 6 lines.
In total : 12 lines.
Current : 17 points.
In total : 29 points.
Current : 6 lines.
In total : 13 lines.
Current : 15 points.
In total : 29 points.
Current : 9 lines.
In total : 17 lines.
Current : 21 points.
In total : 37 points.
Current : 13 lines.
In total : 21 lines.
Current : 21 points.
In total : 45 points.
HINT

Append Code
append.cc,
[Submit][Status]

*/