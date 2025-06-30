#include <algorithm>
#include <iostream>
using namespace std;
class OrdSet {
private:
  int *data, n;

protected:
public:
  OrdSet() : data(NULL), n(0) {}
  void input() {
    cin >> n;
    data = new int[n];
    for (int i = 0; i < n; i++)
      cin >> data[i];
    sort(data, data + n);
    n = unique(data, data + n) - data;
  }
  OrdSet operator+(const OrdSet &other) {
    OrdSet result;
    result.data = new int[n + other.n];
    int i = 0, j = 0, k = 0;
    while (i < n && j < other.n)
      if (data[i] < other.data[j])
        result.data[k++] = data[i++];
      else if (data[i] > other.data[j])
        result.data[k++] = other.data[j++];
      else
        result.data[k++] = data[i++], j++;
    while (i < n)
      result.data[k++] = data[i++];
    while (j < other.n)
      result.data[k++] = other.data[j++];
    result.n = k;
    return result;
  }
  OrdSet operator*(const OrdSet &other) {
    OrdSet result;
    result.data = new int[max(n, other.n)];
    int i = 0, j = 0, k = 0;
    while (i < n && j < other.n)
      if (data[i] < other.data[j])
        i++;
      else if (data[i] > other.data[j])
        j++;
      else
        result.data[k++] = data[i++], j++;
    result.n = k;
    return result;
  }
  void output() {
    cout << "[";
    for (int i = 0; i < n; i++)
      cout << (i ? " " : "") << data[i];
    cout << (n ? "" : "NULL") << "]" << endl;
  }
};
int main() {
  OrdSet os, o1, o2, o3;
  o1.input();
  o2.input();
  o3.input();
  os = o1 + o2 + o3;
  os.output();
  os = o1 * o2 * o3;
  os.output();
  return 0;
}

/*

Description

设计一个存储整数的有序集合类，其中的数据是按照从小到大的顺序存储的。

用C++编写OrdSet类来完成代码，调用格式见“Append Code”。

OrdSet::input()按格式输入数据。

OrdSet::output()按格式输出数据。

OrdSet类上的运算符“+”表示集合的并运算，“*”表示集合的交运算。

STL容器：set、map、vector、deque、queue、stack、array、list等被禁用。万能头文件被禁用

Input

输入为三个集合：每个集合首先输入一个整数n（n>=0）。后接n个整数（有可能重复，重复的整数是集合中的同一个元素）。若n=0，则后续无输入。

Output

输出用“[”和“]”包括起来有序集合的元素，按从小到大的顺序。例如：空集输出为“[NULL]”，只有一个元素0的集合输出为“[0]”。集合多个元素间用一个空格隔开。

Sample Input
8
6 2 6 1 2 6 1 2
4
6 2 1 4
6
3 5 6 7 7 1
Sample Output
[1 2 3 4 5 6 7]
[1 6]
HINT

Append Code
append.cc,
[Submit][Status]

*/
