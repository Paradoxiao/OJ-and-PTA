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