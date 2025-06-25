#include <iostream>
#include <istream>
#include <vector>
using namespace std;
class Matrix {
private:
  vector<vector<int> > data;

protected:
public:
  Matrix(int m = 0, int n = 0) {
    data.resize(m, vector<int>(n));
  }
  friend istream &operator>>(istream &in, Matrix &m) {
    int rows, cols;
    in >> rows >> cols;
    m.data.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        in >> m.data[i][j];
    return in;
  }
  friend ostream &operator<<(ostream &out, const Matrix &m) {
    if (m.data.empty() || m.data[0].empty()) {
      out << "Error" << endl;
      return out;
    }
    for (int i = 0; i < m.data.size(); i++) {
      for (int j = 0; j < m.data[i].size(); j++) {
        out << m.data[i][j];
        if (j < m.data[i].size() - 1)
          out << " ";
      }
      cout << endl;
    }
    return out;
  }
  Matrix operator+(const Matrix &other) const {
    if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
      return Matrix(0, 0);
    }
    Matrix result(data.size(), data[0].size());
    result.data.resize(data.size(), vector<int>(data[0].size()));
    for (int i = 0; i < data.size(); i++)
      for (int j = 0; j < data[i].size(); j++)
        result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
  }
  Matrix operator*(const Matrix &other) const {
    if (data[0].size() != other.data.size()) {
      return Matrix(0, 0);
    }
    Matrix result;
    result.data.resize(data.size(), vector<int>(other.data[0].size(), 0));
    for (int i = 0; i < data.size(); i++)
      for (int j = 0; j < other.data[0].size(); j++)
        for (int k = 0; k < data[0].size(); k++)
          result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
  }
};
int main() {
  int cases, i;
  cin >> cases;
  for (i = 0; i < cases; i++) {
    Matrix A, B, C, D;
    cin >> A >> B;
    C = A + B;
    D = A * B;
    cout << "Case " << i + 1 << ":" << endl;
    cout << C << endl;
    cout << D;
  }
  return 0;
}

/*

Description

定义一个Matrix类，用于存储一个矩阵。重载其+、*运算符，分别用于计算两个矩阵的和、乘积；重载其<<和>>运算符，用于输出和输入一个矩阵。要求当两个矩阵不能进行加法或乘法运算时，应该输出Error。

Input

输入第1行N>0，表示有N组测试用例，共2N个矩阵。

每组测试用例包括2个矩阵。每个矩阵首先输入行数、列数，之后是该矩阵的所有元素。

Output

每个测试用例产生一组输出。具体格式见样例。注意：当不能进行加法或乘法运算时，应输出Error。

Sample Input
3
2 2
1 1
1 1
2 2
2 2
2 2
1 1
1
1 2
2 2
1 1
1
2 2
2 2
2 2
Sample Output
Case 1:
3 3
3 3

4 4
4 4
Case 2:
Error

2 2
Case 3:
Error

Error
HINT

Append Code
append.cc,
[Submit][Status]

*/
