#include <algorithm>
#include <iostream>
using namespace std;
class MySet {
private:
  int *array;
  int len;

public:
  MySet();
  MySet(int *, int);
  MySet(const MySet &);
  ~MySet();
  bool in_set(int) const;
  MySet &operator=(const MySet &);
  MySet operator+(const MySet &) const;
  MySet operator-(const MySet &);
  MySet operator*(const MySet &);
  friend MySet SA(const MySet &A, const MySet &B);
  friend MySet SB(const MySet &A, const MySet &B);
  friend ostream &operator<<(ostream &, const MySet &);
  friend istream &operator>>(istream &, MySet &);
};

using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    MySet a, b;
    cin >> a >> b;
    cout << "Case# " << i + 1 << ":" << endl;
    cout << "A = " << a;
    cout << "B = " << b;
    cout << "A u B = " << a + b;
    cout << "A n B = " << a * b;
    cout << "A - B = " << a - b;
    cout << "SA = " << SA(a, b);
    cout << "SB = " << SB(a, b);
  }
  return 0;
}

MySet::MySet() : array(NULL), len(0) {}
MySet::MySet(int *arr, int n) {
  array = new int[n];
  copy(arr, arr + n, array);
  sort(array, array + n);
  len = unique(array, array + n) - array;
}
MySet::MySet(const MySet &other) {
  array = new int[other.len];
  copy(other.array, other.array + other.len, array);
  len = other.len;
}
MySet::~MySet() {
  delete[] array;
}
bool MySet::in_set(int n) const {
  for (int i = 0; i < len; i++)
    if (array[i] == n)
      return true;
  return false;
}
MySet &MySet::operator=(const MySet &other) {
  delete[] array;
  array = new int[other.len];
  copy(other.array, other.array + other.len, array);
  len = other.len;
  return *this;
}
MySet MySet::operator+(const MySet &other) const {
  MySet result;
  result.array = new int[len + other.len];
  result.len = set_union(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator-(const MySet &other) {
  MySet result;
  result.array = new int[len];
  result.len = set_difference(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet MySet::operator*(const MySet &other) {
  MySet result;
  result.array = new int[min(len, other.len)];
  result.len = set_intersection(array, array + len, other.array, other.array + other.len, result.array) - result.array;
  return result;
}
MySet SA(const MySet &A, const MySet &B) {
  int *temp = new int[A.len + B.len], k = 0;
  MySet U = A + B;
  for (int i = 0; i < U.len; i++)
    if (!A.in_set(U.array[i]))
      temp[k++] = U.array[i];
  return MySet(temp, k);
}
MySet SB(const MySet &A, const MySet &B) {
  int *temp = new int[A.len + B.len], k = 0;
  MySet U = A + B;
  for (int i = 0; i < U.len; i++)
    if (!B.in_set(U.array[i]))
      temp[k++] = U.array[i];
  return MySet(temp, k);
}
ostream &operator<<(ostream &os, const MySet &my_set) {
  os << "{";
  for (int i = 0; i < my_set.len; i++)
    os << (i ? ", " : "") << my_set.array[i];
  os << "}" << endl;
  return os;
}
istream &operator>>(istream &is, MySet &my_set) {
  int n;
  is >> n;
  delete[] my_set.array;
  my_set.array = new int[n];
  my_set.len = n;
  for (int i = 0; i < n; i++)
    is >> my_set.array[i];
  sort(my_set.array, my_set.array + n);
  my_set.len = unique(my_set.array, my_set.array + n) - my_set.array;
  return is;
}
/*

Description
集合的运算就是用给定的集合去指定新的集合。设A和B是集合，则它们的并差交补集分别定义如下：
A∪B={x|x∈A∨x∈B}
A∩B={x|x∈A∧x∈B}
A-B={x|x∈A∧x不属于 B}
SA ={x|x∈(A∪B)∧x 不属于A}
SB ={x|x∈(A∪B)∧x 不属于B}

Input
第一行输入一个正整数T，表示总共有T组测试数据。（T<=200）
然后下面有2T行，每一行都有n+1个数字，其中第一个数字是n(0<=n<=100)，表示该行后面还有n个数字输入。

Output
对于每组测试数据，首先输出测试数据序号，”Case #.NO”，
接下来输出共7行，每行都是一个集合，
前2行分别输出集合A、B，接下5行来分别输出集合A、B的并(A u B)、交(A n B)、差(A – B)、补。
集合中的元素用“{}”扩起来，且元素之间用“， ”隔开。

Sample Input
1
4 1 2 3 1
0
Sample Output
Case# 1:
A = {1, 2, 3}
B = {}
A u B = {1, 2, 3}
A n B = {}
A - B = {1, 2, 3}
SA = {}
SB = {1, 2, 3}
HINT

如果你会用百度搜一下关键字“stl set”，这个题目我相信你会很快很轻松的做出来。加油哦！


Append Code
[Submit][Status]

*/
