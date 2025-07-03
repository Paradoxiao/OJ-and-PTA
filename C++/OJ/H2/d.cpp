#include <iostream>
void get_num(int &a, int &b) {
  std::cin >> a >> b;
}
void put_sum(int a, int b) {
  std::cout << a + b;
}
int main() {
  int a, b;
  get_num(a, b);
  put_sum(a, b);
}
/*

Description

         输入两个整数，输出它们的和。

 

         编写两个函数get_num()、put_sum()，完成程序。功能：

                   函数get_num()读取输入的两个整数；

                   函数put_sum()输出这两个整数的和;

         调用格式见“Append Code”。
Input

          输入为两个整数，用空格分开。

Output

          输出是一个整数，表示输入两数之和。

Sample Input
1 2
Sample Output
3
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/