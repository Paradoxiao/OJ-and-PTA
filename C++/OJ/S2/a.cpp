#include <iostream>
using namespace std;
class Pear {
  double pear_weight;

public:
  Pear(double w = 0) : pear_weight(w) {
    cout << pear_weight << "kg pear is created." << endl;
  }
  ~Pear() {
    cout << pear_weight << "kg pear is erased." << endl;
  }
  Pear(const Pear &p) : pear_weight(p.pear_weight) {
    cout << pear_weight << "kg pear is copied." << endl;
  }
  double weight() const {
    return pear_weight;
  }
  void weight(double w) {
    pear_weight = w;
  }
};
int main() {
  double w;
  cin >> w;
  Pear pe(w), pea, pear(pe);
  cin >> w;
  pear.weight(w);
  cout << pear.weight() << endl;
}
/*

Description
         Jackie开了一家水果店，店里有三箱梨（Pear），梨的属性是重量（weight）。其中有一箱梨需要重新称重。请你编写程序完成这个步骤。
用C++编写Pear类来完成代码，调用格式见“Append Code”。
Pear::weight()梨的重量。
Pear::weight()修改梨的重量。
Pear的构造、拷贝和析构，根据题意设计。

Input
         输入是两箱梨的重量。

Output
         根据输出样例编写构造、拷贝和析构函数完成输出。

Sample Input
11
22
Sample Output
11kg pear is created.
0kg pear is created.
11kg pear is copied.
22
22kg pear is erased.
0kg pear is erased.
11kg pear is erased.
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/