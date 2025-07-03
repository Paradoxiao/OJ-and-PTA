#include <algorithm>
#include <iostream>
using namespace std;
class OrdSet {
private:
  int *arr, n;

public:
  OrdSet() : arr(NULL), n(0) {}
  void input() {
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    sort(arr, arr + n);
    n = unique(arr, arr + n) - arr;
  }
  void output() {
    if (!n) {
      cout << "[NULL]" << endl;
      return;
    }
    cout << "[";
    for (int i = 0; i < n; i++)
      cout << (i ? " " : "") << arr[i];
    cout << "]";
  }
};
int main() {
  OrdSet os;
  os.input();
  os.output();
  return 0;
}
/*

Description

设计一个存储整数的有序集合类，其中的数据是按照从小到大的顺序存储的。

用C++编写OrdSet类来完成代码，调用格式见“Append Code”。

OrdSet::input()按格式输入数据。

OrdSet::output()按格式输出数据。

STL容器：set、map、vector、deque、queue、stack、array、list等被禁用。万能头文件被禁用

Input

首先输入一个整数n（n>=0）。后接n个不同的整数。若n=0，则后续无输入。

Output

输出用“[”和“]”包括起来有序集合的元素，按从小到大的顺序。例如：空集输出为“[NULL]”，只有一个元素0的集合输出为“[0]”。集合多个元素间用一个空格隔开。

Sample Input
5
8 2 6 1 4
Sample Output
[1 2 4 6 8]
HINT

Append Code
append.cc,
[Submit][Status]

*/