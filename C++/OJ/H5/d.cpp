#include <iomanip>
#include <iostream>
using namespace std;
class Point {
private:
  double x, y;

public:
  Point(double x = 0.00, double y = 0.00) : x(x), y(y) {
    cout << "The Point (" << setprecision(2) << fixed << x << ", " << setprecision(2) << fixed << y << ") is created!" << endl;
  }
  Point(const Point &other) : x(other.x), y(other.y) {
    cout << "A Point (" << setprecision(2) << fixed << x << ", " << setprecision(2) << fixed << y << ") is copied!" << endl;
  }
  ~Point() {
    cout << "A Point (" << setprecision(2) << fixed << x << ", " << setprecision(2) << fixed << y << ") is erased!" << endl;
  }
  double getX() {
    return x;
  }
  double getY() {
    return y;
  }
  Point &operator=(const Point &other) {
    x = other.x, y = other.y;
    return *this;
  }
};
class Graph {
private:
  Point *points;
  int n;

public:
  Graph(Point *p, int n) : points(new Point[n]), n(n) {
    for (int i = 0; i < n; i++)
      points[i] = p[i];
    cout << "A graph with " << n << " points is created!" << endl;
  }
  ~Graph() {
    delete[] points;
    cout << "A graph with " << n << " points is erased!" << endl;
  }
  Point getCentroid() {
    double x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      x += points[i].getX();
      y += points[i].getY();
    }
    return *new Point(x / n, y / n);
  }
};
int main() {
  int cases, num;
  double x, y;
  Point centroid;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> num;
    Point points[num];
    for (int j = 0; j < num; j++) {
      cin >> x >> y;
      points[j] = *(new Point(x, y));
    }
    Graph graph(points, num);
    centroid = graph.getCentroid();
    cout << setprecision(2) << fixed << "The centroid is (" << centroid.getX() << ", " << centroid.getY() << ")." << endl;
  }
  return 0;
}
