#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T> class Array {
private:
  T *arr;
  int capacity;
  int size;

public:
  Array(int n) : arr(new T[n]), capacity(n), size(0) {}
  Array(const Array &other) : capacity(other.capacity), size(other.size) {
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
      arr[i] = other.arr[i];
  }
  Array() : arr(NULL), capacity(0), size(0) {}
  void input(int n) {
    if (n > capacity)
      n = capacity;
    for (size = 0; size < n; size++)
      cin >> arr[size];
  }
  T operator[](int index) const {
    return arr[index];
  }
};
class Fract {
private:
  int n, m;
  void simplify() {
    int a = n, b = m;
    int gcd = 1;
    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;
    while (b != 0) {
      int t = b;
      b = a % b, a = t;
    }
    gcd = a;
    if (gcd != 0)
      n /= gcd, m /= gcd;
  }

public:
  Fract() : n(0), m(1) {}
  Fract(int n, int m) : n(n), m(m) {
    simplify();
  }
  friend istream &operator>>(istream &is, Fract &f) {
    is >> f.n >> f.m;
    f.simplify();
    return is;
  }
  friend ostream &operator<<(ostream &os, const Fract &f) {
    if (f.n == 0) {
      os << "0";
      return os;
    }
    if (f.n * f.m < 0)
      os << "-";
    os << (f.n >= 0 ? f.n : -f.n);
    if (f.m != 1 && f.m != -1)
      os << "/" << (f.m >= 0 ? f.m : -f.m);
    return os;
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
  Fract operator+=(const Fract &f) {
    n = n * f.m + f.n * m;
    m *= f.m;
    simplify();
    return *this;
  }
};
int main() {
  int n;
  cin >> n;
  Array<double> db(1000);
  db.input(n);
  double dbsum(0.0);
  for (int i = 0; i < n; i++)
    dbsum += db[i];
  cout << dbsum << endl;

  cin >> n;
  Array<Fract> fr(1000);
  fr.input(n);
  Fract frsum(0, 1);
  for (int i = 0; i < n; i++)
    frsum += fr[i];
  frsum.show();
}

/*

Description
封装一个模板数组类Array，支持一下操作：
1. 构造函数Array(int n)，将数组初始化为n个存储空间；
2. 函数input(int n)，读取最多n个元素，但不能超过数组存储空间的上限；
3. 重载下标运算符，返回数组的元素。
封装一个分数类Fract，用来处理分数功能和运算，能支持你的Array类使用。
1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。
2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。
3. 在分数类上重载+=运算符，进行分数的加法运算。
-----------------------------------------------------------------------------
你设计两个类：Array类和Fract类，使得main()函数能够运行并得到正确的输出。调用格式见append.cc

Input
输入为两部分，分别是一组实数测试样例和一组复数测试样例。
这两组测试样例都以正整数n，且n小于1000，n表示需要输入n个实数（或分数）。
测试样例的第二行开始为n个实数（或分数）。其中每个分数输入为两个整数n、m，表示分数n/m。

Output
第一部分输出一个实数，是第一组测试样例之和；第二部分输出一个分数，是第二组测试样例之和。
分数输出时为最简形式，负号只会出现在最前面，若分母为1或分子为0，则只输出一个整数，即分子部分，而没有“/”和分母部分。

Sample Input
4
6 8 7 5
9
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
26
-17117/2640
HINT

*/
