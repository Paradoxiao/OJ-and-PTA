#include <iostream>
using namespace std;
class Vector {
private:
  int x, y, z;

protected:
public:
  Vector(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
  Vector operator+(const Vector &other) {
    return Vector(x + other.x, y + other.y, z + other.z);
  }
  Vector operator*(int n) {
    return Vector(x * n, y * n, z * n);
  }
  Vector operator*(const Vector &other) {
    return Vector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
  }
  friend istream &operator>>(istream &is, Vector &other) {
    is >> other.x >> other.y >> other.z;
    return is;
  }
  friend ostream &operator<<(ostream &os, const Vector &other) {
    bool not_first = 0;
    if (other.x) {
      os << other.x << "i";
      not_first = 1;
    }
    if (other.y) {
      os << (not_first && other.y >= 0 ? "+" : "") << other.y << "j";
      not_first = 1;
    }
    if (other.z) {
      os << (not_first && other.z >= 0 ? "+" : "") << other.z << "k";
      not_first = 1;
    }
    if (!not_first)
      os << 0;
    return os;
  }
};
int main() {
  Vector vec1, vec2, vec3;
  int cases, n;
  cin >> cases;
  cout << "vect+vec2\tn*vec1\tvec1*vec2\n";
  for (int i = 0; i < cases; i++) {
    cin >> vec1 >> vec2 >> n;
    vec3 = vec1 + vec2;
    cout << vec3 << "\t";
    vec3 = vec1 * n;
    cout << vec3 << "\t";
    vec3 = vec1 * vec2;
    cout << vec3 << endl;
  }
  return 0;
}

/*

Description

编写类Vector，用于表示一个向量。显然：

1. 它有三个数据成员，假定均为int类型的量，表示3个方向上的分量。

2. 定义其无参构造函数，初始化三个分量为0。

3.定义带参构造函数，用于初始化向量。

4. 重载+、-、*、<<和>>运算符。其中“+”和“-”不改变操作数的值，只是返回运算结果；“*”实现两种乘法，包括数乘及叉积。

Input

输入有多行，第一行M>0，表示有M个测试用例，之后有M行。

每行包括7个部分：前3个表示一个向量的三个分量，中间3个表示另一个向量的三个分量，最后一个为一个int类型的数。

分量的顺序按照i、j、k给出。

Output

输出见样例。其中：如果某个分量为0，则不输出该数量，除非所有分量均为0，则输出0。如果某个分量为负数，则不应输出其前面的“+”号。

Sample Input
7
1 1 1 1 1 1 3
1 2 3 3 2 1 4
-1 -2 -3 -3 -2 -1 10
1 2 3 -1 2 3 5
1 2 3 1 -2 3 6
1 2 3 1 2 -3 9
1 2 3 -1 -2 -3 5
Sample Output
vect+vec2	n*vec1	vec1*vec2
2i+2j+2k	3i+3j+3k	0
4i+4j+4k	4i+8j+12k	-4i+8j-4k
-4i-4j-4k	-10i-20j-30k	-4i+8j-4k
4j+6k	5i+10j+15k	-6j+4k
2i+6k	6i+12j+18k	12i-4k
2i+4j	9i+18j+27k	-12i+6j
0	5i+10j+15k	0
HINT

Append Code
append.cc,
[Submit][Status]

*/
/*

*/
