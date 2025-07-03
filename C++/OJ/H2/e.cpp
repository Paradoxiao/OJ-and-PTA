#include <iostream>
using namespace std;
int func(int = 0, int = 0, int = 0);
int main() {
  int m;
  std::cin >> m;
  func();
  func(m, 100);
  func(m, 23, -5);
}

int func(int a, int b, int c) {
  std::cout << "Number " << a << " " << b << " " << c << std::endl;
  return 0;
}
/*

Description

         输入两个整数，输出它们的和。

 

         编写函数func()的函数声明，完成程序。函数func()功能是输出三个整数，函数定义、调用和输出格式见“Append Code”。

Input

         输入为一个整数。

Output

         调用函数func()输出。

Sample Input
12
Sample Output
Number 0 0 0
Number 12 100 0
Number 12 23 -5
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/