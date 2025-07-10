#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Vec {
private:
  vector<int> data;

protected:
public:
  friend istream &operator>>(istream &in, Vec &v) {
    int n;
    in >> n;
    v.data.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.data.push_back(x);
    }
    v.data.resize(unique(v.data.begin(), v.data.end()) - v.data.begin());
    return in;
  }
  friend ostream &operator<<(ostream &out, const Vec &v) {
    for (size_t i = 0; i < v.data.size(); ++i)
      out << (i ? " " : "") << v.data[i];
    out << endl;
    return out;
  }
  Vec operator+(const Vec &other) const {
    Vec result;
    result.data = data;
    for (vector<int>::const_iterator it = other.data.begin(); it != other.data.end(); ++it)
      result.data.push_back(*it);
    sort(result.data.begin(), result.data.end());
    result.data.resize(unique(result.data.begin(), result.data.end()) - result.data.begin());
    return result;
  }
};
int main() {
  Vec v1, v2, v3;
  cin >> v1;
  cin >> v2;
  cout << "v1:" << v1;
  cout << "v2:" << v2;
  v3 = v1 + v2;
  cout << "v1:" << v1;
  cout << "v2:" << v2;
  cout << "v3:" << v3;
  return 0;
}

/*

Description
定义Vec类，是由int类型的数据组成的向量，重载其输入、输出运算符，以及加法运算符。
其中，输入一个整型向量时，输入的是一个非减排序的整数序列，其中包含重复值，在输入时，重复值只保留1个，即Vec类中的向量是递增排序且不含重复值的。
输出时，两两之间用一个空格隔开。
加法运算，将两个Vec类的对象中的整型向量合并为一个不含重复值的递增序列，不能修改两个操作数的值。

Input
输入有2行。每行是一个向量。
每行第一个值是一个正整数N>0，表示后面有N个输入的整数。

Output

见样例

Sample Input
10 1 1 1 3 3 3 4 5 8 8
5 1 2 3 4 5
Sample Output
v1:1 3 4 5 8
v2:1 2 3 4 5
v1:1 3 4 5 8
v2:1 2 3 4 5
v3:1 2 3 4 5 8
HINT

Append Code
append.cc,
[Submit][Status]

*/
