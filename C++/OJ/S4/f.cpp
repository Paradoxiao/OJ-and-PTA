#include <iostream>
using namespace std;
template <typename T> class Compute {
public:
  static T getMax(T a, T b, T c) {
    return (a > b ? a : b) > c ? (a > b ? a : b) : c;
  }
  static T getMax(T a, T b) {
    return a > b ? a : b;
  }
};
int main() {
  int a, b, c;
  double x, y, z;
  cin >> a >> b >> c;
  cout << Compute<int>::getMax(a, b) << " " << Compute<int>::getMax(a, b, c) << endl;
  cin >> x >> y >> z;
  cout << Compute<double>::getMax(x, y) << " " << Compute<double>::getMax(x, y, z) << endl;
  return 0;
}

/*

Description

定义一个类模板Compute，其中有两个重载的静态成员函数getMax，分别用于求2个数的最大值和3个数的最大值。
Input

输入有2行，第1行是3个整数，第2行是3个实数。
Output

输出有两行，第一行分别输出前2个整数的最大值、所有3个整数的最大值；第二行输出前2个实数的最大值、所有3个实数的最大值。
Sample Input
10 20 30
10.11 20.22 -9.99
Sample Output
20 30
20.22 20.22
HINT

*/
