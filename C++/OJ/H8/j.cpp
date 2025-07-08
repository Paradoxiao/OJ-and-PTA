#include <iostream>
using namespace std;
double area(double r) {
  return 3.14 * r * r;
}
double area(double x, double y) {
  return x * y;
}
int main() {
  double r, x, y;
  cin >> r;
  cin >> x >> y;
  cout << area(r) << endl;
  cout << area(x, y) << endl;
}

/*

Description

编写两个名为area的函数，它们是重载函数 ，用于求圆的面积和长方形的面积。它们的原型分别是：

double area(double r);

double area(double a,double b);

返回值分别是圆的面积和长方形的面积。
Input

输入两行，第一行是一个double型的实数，表示圆的半径；第二行是两个double型的实数，表示长方形的长和宽。
Output

输出2个数，每个数占一行。第一个数表示圆的面积，第二个数表示长方形的面积。
Sample Input
1.2
1.2 3.4
Sample Output
4.5216
4.08
HINT

Append Code
append.cc,
[Submit][Status]

*/
