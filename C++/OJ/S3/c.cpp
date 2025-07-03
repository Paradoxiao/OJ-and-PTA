#include <iostream>
using namespace std;
class Fract {
private:
  int n, m;

public:
  Fract(int n, int m) : n(n), m(m) {
    int a = n, b = m;
    int gcd = 1;
    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;
    while (b != 0) {
      int t = b;
      b = a % b;
      a = t;
    }
    gcd = a;
    if (gcd != 0) {
      this->n /= gcd;
      this->m /= gcd;
    }
  }
  operator double() {
    if (n == 0)
      return 0;
    double a = n, b = m;
    return a / b;
  }
  void show() {
    if (n == 0) {
      cout << "0" << endl;
      return;
    }
    if (n * m < 0)
      cout << "-";
    cout << (n >= 0 ? n : -n);
    if (m != 1 && m != -1)
      cout << "/" << (m >= 0 ? m : -m);
    cout << endl;
  }
};
int main() {
  int n, m;
  while (cin >> n >> m) {
    Fract fr(n, m);
    cout << (double)fr << " ";
    fr.show();
  }
}
/*

Description
封装一个分数类Fract，用来处理分数功能和运算，支持以下操作：
1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。
2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。
3. double类型转换函数：用分子除以分母，得到的小数。注意：分子为0时不要输出为“-0”
-----------------------------------------------------------------------------
你设计一个Fract类，使得main()函数能够运行并得到正确的输出。调用格式见append.cc

Input
输入多行，每行两个整数，分别为分子和分母，至EOF结束。输入的分母不会为0；

Output
每行输出一个实数和分数，与输入顺序一致。实数为分子除以分母所得。
分数输出时为最简形式，负号只会出现在最前面，若分母为1或分子为0，则只输出一个整数，即分子部分，而没有“/”和分母部分。

Sample Input
1 3
20 -15
80 150
-9 1
6 6
12 16
-33 -48
6 11
0 -10
Sample Output
0.333333 1/3
-1.33333 -4/3
0.533333 8/15
-9 -9
1 1
0.75 3/4
0.6875 11/16
0.545455 6/11
0 0
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/