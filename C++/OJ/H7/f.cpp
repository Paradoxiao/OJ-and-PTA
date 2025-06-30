#include <iostream>
#include <vector>
using namespace std;
class Mandarin {
private:
  double price, mass;

protected:
public:
  Mandarin(double price) : price(price) {}
  void weight(double w) {
    mass = w;
  }
  double value() {
    return price * mass;
  }
};
class MandarinBox {
private:
  vector<Mandarin> man;

protected:
public:
  MandarinBox(double price) : man(6, Mandarin(price)) {}
  Mandarin &operator[](int i) {
    return man[i];
  }
  double value() {
    double sum = 0;
    for (int i = 0; i < 6; i++)
      sum += man[i].value();
    return sum;
  }
};
int main() {
  double price, w;

  cin >> price;
  MandarinBox mandarin(price);
  for (int i = 0; i < 6; i++) {
    cin >> w;
    mandarin[i].weight(w);
  }
  cout << mandarin.value() << endl;
}

/*

Description
         Jackie开了一家水果店，店里新进了一些橘子（Mandarin），现在需要把它们装箱（MandarinBox），每箱有6个橘子。现在知道橘子的单价（每公斤价格）和每个橘子的重量（公斤数）。请你编写程序计算这箱橘子的价格。
用C++编写Mandarin类和MandarinBox来完成代码，调用格式见“Append Code”。
Manadarin::weight(double)修改橘子的重量。
MandarinBox::value()一箱橘子的价格。
ManadarinBox重载下标运算符，取出下标对应的橘子。
ManadarinBox构造，初始化橘子的单价。

Input
         第一行输入橘子的单价，第二行是6个橘子的重量。

Output
       输出这箱橘子的价格。

Sample Input
5.8
0.8 1.1 0.95 0.92 0.77 0.84
Sample Output
31.204
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
