#include <algorithm>
#include <iostream>
using namespace std;
class OrdSet {
private:
  int *arr;
  int len;

public:
  OrdSet() : arr(NULL), len(0) {}
  void input() {
    cin >> len;
    delete[] arr;
    arr = new int[len];
    for (int i = 0; i < len; ++i)
      cin >> arr[i];
    sort(arr, arr + len);
    len = unique(arr, arr + len) - arr;
  }
  void output() {
    if (len <= 0) {
      cout << "[NULL]" << endl;
      return;
    }
    cout << "[";
    for (int i = 0; i < len; i++)
      cout << (i > 0 ? " " : "") << arr[i];
    cout << "]" << endl;
  }
  bool is_member(int num) {
    for (int i = 0; i < len; ++i) {
      if (arr[i] == num)
        return true;
      if (arr[i] > num)
        return false;
    }
    return false;
  }
};
int main() {
  OrdSet os;
  os.input();
  os.output();
  int num;
  while (cin >> num) {
    cout << num << " is";
    if (!os.is_member(num))
      cout << " not";
    cout << " in it." << endl;
  }
  return 0;
}

/*

Description

设计一个存储整数的有序集合类，其中的数据是按照从小到大的顺序存储的。

用C++编写OrdSet类来完成代码，调用格式见“Append Code”。

OrdSet::input()按格式输入数据。

OrdSet::output()按格式输出数据。

OrdSet::is_member()判断参数元素是否在集合内。

STL容器：set、map、vector、deque、queue、stack、array、list等被禁用。万能头文件被禁用

Input

首先输入一个整数n（n>=0）。后接n个整数（有可能重复，重复的整数是集合中的同一个元素）。若n=0，则后续无输入。

然后输入若干整数，询问这些整数是否是集合的成员。

Output

输出用“[”和“]”包括起来有序集合的元素，按从小到大的顺序。例如：空集输出为“[NULL]”，只有一个元素0的集合输出为“[0]”。集合多个元素间用一个空格隔开。

判断是否集合成员的输出格式见样例。

Sample Input
8
6 2 6 1 2 6 4 8
3
6
Sample Output
[1 2 4 6 8]
3 is not in it.
6 is in it.
HINT

Append Code

*/
