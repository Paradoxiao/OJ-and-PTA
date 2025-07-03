#include <iostream>
using namespace std;
class Data {
  int a;
  double b;

public:
  Data() {
    a = b = 2147483647;
    cout << "A default object is created.\n";
  }
  Data(int a) : a(a) {
    b = 2147483647;
    cout << "An integer object " << a << " is created.\n";
  }
  Data(double b) : b(b) {
    a = 2147483647;
    cout << "A double object " << b << " is created.\n";
  }
  ~Data() {
    if (a != 2147483647 && b == 2147483647) {
      cout << "The integer object " << a << " is erased.\n";
      return;
    }
    if (b != 2147483647 && a == 2147483647) {
      cout << "The double object " << b << " is erased.\n";
      return;
    }
    cout << "The default object is erased.\n";
  }
};
int main() {
  Data d1;
  int i;
  cin >> i;
  Data d2(i);
  double d;
  cin >> d;
  Data d3(d);
  return 0;
}

/*

Description

定义一个Data类，至少包含1个int类型的数据成员、1个double类型的数据成员，定义其构造函数和析构函数，使得程序执行时，能产生样例所示的结果。
Input

输入2行，第1行是1个int类型的数据，第2行是1个double类型的数据。
Output

见样例。
Sample Input
120
3.14
Sample Output
A default object is created.
An integer object 120 is created.
A double object 3.14 is created.
The double object 3.14 is erased.
The integer object 120 is erased.
The default object is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/