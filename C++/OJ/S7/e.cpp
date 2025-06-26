#include <iostream>
#include <istream>
#include <vector>
using namespace std;
class Array {
private:
  vector<int> data;

protected:
public:
  Array operator-(int a) {
    Array result;
    for (int i = 0; i < data.size(); i++)
      if (data[i] != a)
        result.data.push_back(data[i]);
    return result;
  }
  friend istream &operator>>(istream &is, Array &o) {
    o.data.clear();
    int n, m;
    is >> n;
    for (int i = 0; i < n; i++) {
      is >> m;
      o.data.push_back(m);
    }
    return is;
  };
  friend ostream &operator<<(ostream &os, const Array &o) {
    for (int i = 0; i < o.data.size(); i++)
      os << (i ? " " : "") << o.data[i];
    os << endl;
    return os;
  }
};
int main() {
  int a;
  Array arr;
  cin >> arr;
  cout << arr;
  cin >> a;
  arr = arr - a;
  cout << arr;
  return 0;
}

/*

Description

定义Array类，其中只有一个int类型的数组，数组元素个数未知。

重载其<<、>>、-运算符。其中"<<"输出所有的数组元素，两两之间用1个空格隔开；">>"根据输入的格式读取数组元素；"-"接收一个int类型的参数a，将数组中与a相等的元素删除。
Input

输入有3行。第一行N>0；第二行是N个整数，是数组元素；第3行是一个int类型数，是需要从数组中删除的数。
Output

见样例。
Sample Input
10
1 2 3 4 5 1 2 3 4 5
1
Sample Output
1 2 3 4 5 1 2 3 4 5
2 3 4 5 2 3 4 5
HINT

Append Code
append.cc,
[Submit][Status]

*/
