#include <algorithm>
#include <iostream>
using namespace std;
class Point {
public:
  int *x;
  int n;
  Point(int n) : n(n) {
    x = new int[n];
  }
  Point() : x(NULL), n(0) {}
  friend istream &operator>>(istream &is, Point &p) {
    for (int i = 0; i < p.n; i++)
      is >> p.x[i];
    return is;
  }
  friend ostream &operator<<(ostream &os, const Point &p) {
    cout << "[";
    cout << p.x[0];
    for (int i = 1; i < p.n; i++)
      cout << "," << p.x[i];
    cout << "]";
    return os;
  }
};
bool my_lower(const Point &a, const Point &b) {
  int r1 = 0, r2 = 0;
  for (int i = 0; i < a.n; i++) {
    r1 += a.x[i] * a.x[i];
    r2 += b.x[i] * b.x[i];
  }
  return r1 < r2;
}
class PointList {
private:
  Point *p;
  int size;

public:
  PointList() : p(NULL), size(0) {}
  PointList operator+(const Point &pt) {
    if (!size)
      p = new Point[100];
    p[size++] = pt;
    return *this;
  }
  void Sort() {
    sort(p, p + size, my_lower);
  }
  friend ostream &operator<<(ostream &os, const PointList &pl) {
    for (int i = 0; i < pl.size; i++) {
      os << pl.p[i] << endl;
    }
    return os;
  }
};
int main() {
  PointList pl;
  int m, n, i;
  cin >> m >> n;
  for (i = 0; i < m; i++) {
    Point tmp(n);
    cin >> tmp;
    pl = pl + tmp;
  }
  pl.Sort();
  cout << pl;
  return 0;
}
/*

Description

定义类Point表示一个N维空间中的坐标，定义PointList为若干个Point对象组成的列表。定义：

1.Point::Point(n)方法：用于将坐标的维数设置为n。

2.重载Point的>>运算符，根据Input的格式进行输入一个坐标。

3.重载PointList的<<运算符，根据Output的格式输出PointList的所有坐标值。

4.PointList::Sort()：对PointList中的顶点按照到坐标原点的距离，从小到大排序。

5.重载PointList的+运算符，用于向列表中追加一个点的坐标。

其他所需要的数据成员、函数成员自行定义。
Input

输入有多行。

第一行是两个正整数M和N，其中M表示之后有M个点的坐标，N表示每个点的维数。如M=3,N=2表示有3个二维空间中的点。

之后的M行，每行包含N个整数，表示一个点的坐标。
Output

输出有M行，每行一个点的坐标。

输出时，按照到坐标原点，即[0,0,0,......]的距离从小到大输出。不存在距离相同的点。

每个点的坐标输出格式为：[d1,d2,...]，即：用[]包围一个点的坐标，输出的坐标值两两之间用逗号隔开。

Sample Input
10 2
0 0
1 1
3 3
2 2
9 9
8 8
4 4
6 6
5 5
7 7
Sample Output
[0,0]
[1,1]
[2,2]
[3,3]
[4,4]
[5,5]
[6,6]
[7,7]
[8,8]
[9,9]
HINT

Append Code
append.cc,
[Submit][Status]

*/