#include <iostream>
using namespace std;
class A {
private:
protected:
  int aa;

public:
  A(int aa) : aa(aa) {}
  virtual ~A() {
    cout << "Delete A!" << endl;
  }
  virtual void print() {
    cout << "A : " << aa << endl;
  }
};
class B : virtual public A {
private:
protected:
  int bb;

public:
  B(int aa, int bb) : A(aa), bb(bb) {}
  ~B() {
    cout << "Delete B!" << endl;
  }
  void print() {
    cout << "B : " << aa << " " << bb << endl;
  }
};
class C : virtual public A {
private:
protected:
  int cc;

public:
  C(int aa, int cc) : A(aa), cc(cc) {}
  ~C() {
    cout << "Delete C!" << endl;
  }
  void print() {
    cout << "C : " << aa << " " << cc << endl;
  }
};
class D : virtual public B {
private:
protected:
  int dd;

public:
  D(int aa, int bb, int dd) : A(aa), B(aa, bb), dd(dd) {}
  ~D() {
    cout << "Delete D!" << endl;
  }
  void print() {
    cout << "D : " << aa << " " << bb << " " << dd << endl;
  }
};
class E : virtual public B {
private:
protected:
  int ee;

public:
  E(int aa, int bb, int ee) : A(aa), B(aa, bb), ee(ee) {}
  ~E() {
    cout << "Delete E!" << endl;
  }
  void print() {
    cout << "E : " << aa << " " << bb << " " << ee << endl;
  }
};
class F : virtual public C {
private:
protected:
  int ff;

public:
  F(int aa, int cc, int ff) : A(aa), C(aa, cc), ff(ff) {}
  ~F() {
    cout << "Delete F!" << endl;
  }
  void print() {
    cout << "F : " << aa << " " << cc << " " << ff << endl;
  }
};
int main() {
  A *p[10];
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    int x, y, z;
    cin >> x >> y >> z;
    if (ch == 'A')
      p[i] = new A(x);
    if (ch == 'B')
      p[i] = new B(x, y);
    if (ch == 'C')
      p[i] = new C(x, y);
    if (ch == 'D')
      p[i] = new D(x, y, z);
    if (ch == 'E')
      p[i] = new E(x, y, z);
    if (ch == 'F')
      p[i] = new F(x, y, z);
  }
  for (i = 0; i < n; i++)
    p[i]->print();
  for (i = 0; i < n; i++)
    delete p[i];
}

/*

Description
现在有一个多态问题，需要你用C++类的继承和多态来实现出来。
现在有A、B、C、D、E、F六个类，每个类比自己的父类（如果有的话）多存储一个int类型的成员变量，每个类都有一个print()函数用来输出对象存储的数据。
这六个类满足如下继承关系：A是B、C的父类，B是D、E的父类，C是F的父类。在析构函数里添加适当的代码产生符合对象删除次序的输出。
程序代码见“Append Code”。

Input
         先输入一个n，表示后面有n行数据，每行首先输入一个字符表示类名，然后输入三个整数，用于创建该类的对象。

Output
         输出对象中存储的数据。

Sample Input
2
B 20 30 40
F 666 777 888
Sample Output
B : 20 30
F : 666 777 888
Delete B!
Delete A!
Delete F!
Delete C!
Delete A!
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
