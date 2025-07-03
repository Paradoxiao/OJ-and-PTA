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
  Line(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) : p1(x1, y1), p2(x2, y2) {
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
  void SetLine(double x1, double y1, double x2, double y2) {
    p1.a = x1;
    p1.b = y1;
    p2.a = x2;
    p2.b = y2;
  }
};
int main() {
  char c;
  int num, i;
  double x1, x2, y1, y2;
  Point p(1, -2), q(2, -1), t;
  t.show();
  std::cin >> num;
  Line line[num];
  for (i = 0; i < num; i++) {
    std::cout << "=========================\n";
    std::cin >> x1 >> c >> y1 >> x2 >> c >> y2;
    line[i].SetLine(x1, y1, x2, y2);
    line[i].show();
  }
  std::cout << "=========================\n";
  Line l1(p, q), l2(p, t), l3(q, t), l4(t, q);
  l1.show();
  l2.show();
  l3.show();
  l4.show();
}

/*

Description
在数学上，平面直角坐标系上的点用X轴和Y轴上的两个坐标值唯一确定，两点确定一条线段。现在我们封装一个“Point类”和“Line类”来实现平面上的点的操作。
根据“append.cc”，完成Point类和Line类的构造方法和show()方法，输出各Line对象和Point对象的构造和析构次序。
接口描述：
Point::show()方法：按格式输出Point对象。
Line::show()方法：按格式输出Line对象。

Input

输入的第一行为N，表示后面有N行测试样例。

每行为两组坐标“x,y”，分别表示线段起点和终点的x坐标和y坐标，两组坐标间用一个空格分开，x和y的值都在double数据范围内。

Output
输出为多行，每行为一条线段，起点坐标在前终点坐标在后，每个点的X坐标在前，Y坐标在后，Y坐标前面多输出一个空格，用括号包裹起来。输出格式见sample。
C语言的输入输出被禁用。

Sample Input
4
0,0 1,1
1,1 2,3
2,3 4,5
0,1 1,0
Sample Output
Point : (1, -2) is created.
Point : (2, -1) is created.
Point : (0, 0) is created.
Point : (0, 0)
Point : (0, 0) is created.
Point : (0, 0) is created.
Line : (0, 0) to (0, 0) is created.
Point : (0, 0) is created.
Point : (0, 0) is created.
Line : (0, 0) to (0, 0) is created.
Point : (0, 0) is created.
Point : (0, 0) is created.
Line : (0, 0) to (0, 0) is created.
Point : (0, 0) is created.
Point : (0, 0) is created.
Line : (0, 0) to (0, 0) is created.
=========================
Line : (0, 0) to (1, 1)
=========================
Line : (1, 1) to (2, 3)
=========================
Line : (2, 3) to (4, 5)
=========================
Line : (0, 1) to (1, 0)
=========================
Point : (1, -2) is copied.
Point : (2, -1) is copied.
Line : (1, -2) to (2, -1) is created.
Point : (1, -2) is copied.
Point : (0, 0) is copied.
Line : (1, -2) to (0, 0) is created.
Point : (2, -1) is copied.
Point : (0, 0) is copied.
Line : (2, -1) to (0, 0) is created.
Point : (0, 0) is copied.
Point : (2, -1) is copied.
Line : (0, 0) to (2, -1) is created.
Line : (1, -2) to (2, -1)
Line : (1, -2) to (0, 0)
Line : (2, -1) to (0, 0)
Line : (0, 0) to (2, -1)
Line : (0, 0) to (2, -1) is erased.
Point : (2, -1) is erased.
Point : (0, 0) is erased.
Line : (2, -1) to (0, 0) is erased.
Point : (0, 0) is erased.
Point : (2, -1) is erased.
Line : (1, -2) to (0, 0) is erased.
Point : (0, 0) is erased.
Point : (1, -2) is erased.
Line : (1, -2) to (2, -1) is erased.
Point : (2, -1) is erased.
Point : (1, -2) is erased.
Line : (0, 1) to (1, 0) is erased.
Point : (1, 0) is erased.
Point : (0, 1) is erased.
Line : (2, 3) to (4, 5) is erased.
Point : (4, 5) is erased.
Point : (2, 3) is erased.
Line : (1, 1) to (2, 3) is erased.
Point : (2, 3) is erased.
Point : (1, 1) is erased.
Line : (0, 0) to (1, 1) is erased.
Point : (1, 1) is erased.
Point : (0, 0) is erased.
Point : (0, 0) is erased.
Point : (2, -1) is erased.
Point : (1, -2) is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/