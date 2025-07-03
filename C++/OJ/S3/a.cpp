#include <iostream>
using namespace std;
class Base {
protected:
  int data;

public:
  Base(int d) : data(d) {
    cout << "Base = " << data << " is created." << endl;
  }
  Base(const Base &other) : data(other.data) {
    cout << "Base = " << data << " is copied." << endl;
  }
  ~Base() {
    cout << "Base = " << data << " is erased." << endl;
  }
};
class Derived : public Base {
private:
  int derivedData;

public:
  Derived(int d1, int d2) : Base(d1), derivedData(d2) {
    cout << "Derived = " << derivedData << " is created." << endl;
  }
  Derived(const Derived &other) : Base(other), derivedData(other.derivedData) {
    cout << "Derived = " << derivedData << " is copied." << endl;
  }
  ~Derived() {
    cout << "Derived = " << derivedData << " is erased." << endl;
  }
};
int main() {
  int cases, data1, data2;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> data1 >> data2;
    Base base1(data1), base2(base1);

    Derived derived1(data1, data2), derived2(derived1);
  }
}
/*

Description

定义一个Base类，包括1个int类型的属性，以及满足输出格式要求的构造函数、拷贝构造函数和析构函数。

定义Base类的子类Derived，包括1个int类型的属性， 以及满足输出格式要求的构造函数、拷贝构造函数和析构函数。

Input

第1行N>0表示测试用例个数。

每个测试包括2个int类型的整数。

Output

见样例。

Sample Input
1
10 20
Sample Output
Base = 10 is created.
Base = 10 is copied.
Base = 10 is created.
Derived = 20 is created.
Base = 10 is copied.
Derived = 20 is copied.
Derived = 20 is erased.
Base = 10 is erased.
Derived = 20 is erased.
Base = 10 is erased.
Base = 10 is erased.
Base = 10 is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/