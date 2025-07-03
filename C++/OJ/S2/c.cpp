#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b) {
  return a > b;
}
class Solve {
private:
  int *ji, *ou, j, k, n;

public:
  void input() {
    j = 0, k = 0;
    cin >> n;
    ji = new int[n / 2 + 2];
    ou = new int[n / 2 + 2];
    for (int i = 0; i < n; i++)
      if (i % 2)
        cin >> ji[j++];
      else
        cin >> ou[k++];
  }
  void sort() {
    std::sort(ji, ji + j);
    std::sort(ou, ou + k, cmp);
  }
  void output() {
    j = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (i != 0)
        cout << " ";
      if (i % 2)
        cout << ji[j++];
      else
        cout << ou[k++];
    }
  }
};
int main() {
  Solve solve;
  solve.input();
  solve.sort();
  solve.output();
  return 0;
}
/*

Description

对于给定的一个数组，将下标为偶数的数组元素按照从大到小的顺序排序，将下标为奇数的数组元素按照从小到大的顺序排序。根据题目要求和给定的main函数，编写Solve类，该类至少有如下成员函数：

1. void input()：输入一个数组。

2. void sort()：按照要求对数组进行排序。

3. void output()：按照要求输出数组。
Input

输入有两行，第1行是一个正整数N，表示数组长度为N。第2行是N个整数，是数组元素。
Output

排序后的结果。两两之间用1个空格隔开。
Sample Input
9
10 6 7 3 2 13 6 23 236
Sample Output
236 3 10 6 7 13 6 23 2
HINT

Append Code
append.cc,
[Submit][Status]

*/