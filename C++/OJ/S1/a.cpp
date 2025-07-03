#include <iostream>
using namespace std;
class Integer {
  unsigned long long data;

public:
  void input() {
    cin >> data;
  }
  bool isOdd() {
    return data % 2;
  }
  bool isPrime() {
    if (data < 2)
      return 0;
    if (data == 2)
      return 1;
    for (int i = 2; i * i < data; i++)
      if (data % i == 0)
        return 0;
    return 1;
  }
};
int main() {
  Integer data;
  data.input();
  if (data.isOdd()) {
    cout << "It is an odd number." << endl;
  } else {
    cout << "It is an even number." << endl;
  }
  if (data.isPrime()) {
    cout << "It is a prime." << endl;
  } else {
    cout << "It is not a prime." << endl;
  }
  return 0;
}
/*

Description

定义类Integer，用于判断用户输入的一个正整数是否是合数以及是否为偶数。

该类至少有如下三个方法：

1.input()：用于读取一个正整数。

2.bool isOdd()：用于判断是否为奇数。

3.bool isPrime()：用于判断是否为素数。

请根据main函数和输出定义这个类。
Input

一个正整数。
Output

根据奇偶性，分别输出："It is an odd number."或"It is an even number."。

根据是否为素数，分别输出："It is a prime."或"It is not a prime."。
Sample Input
18
Sample Output
It is an even number.
It is not a prime.
HINT

Append Code
append.cc,
[Submit][Status]

*/