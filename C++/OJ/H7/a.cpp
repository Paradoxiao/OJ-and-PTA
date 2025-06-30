#include <iostream>
#include <vector>
using namespace std;
class Matrix {
private:
  int m, n;
  vector<vector<int> > data;

protected:
public:
  Matrix(int m, int n) : m(m), n(n), data(m, vector<int>(n)) {}
  void input() {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> data[i][j];
  }
  Matrix operator-(const Matrix &other) {
    if (m != other.m || n != other.n)
      return Matrix(0, 0);
    Matrix result(m, n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
  }
  void output() {
    if (m == 0 || n == 0) {
      cout << -1 << endl;
      return;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        cout << (j ? " " : "") << data[i][j];
      cout << endl;
    }
  }
};
int main() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1;
  Matrix M1(r1, c1);
  M1.input();
  cin >> r2 >> c2;
  Matrix M2(r2, c2);
  M2.input();
  (M1 - M2).output();
  return 0;
}
/*

Description

以课上重载的矩阵的+、*运算的方式重载 - 运算

Input

矩阵M1的行数r1，列数c1

矩阵M1

矩阵M2的行数r2，列数c2

矩阵M2

1<=r1,r2,c1,c2<=10

Output

如果可以进行减法 输出M1-M2的结果矩阵
矩阵行之间每两个元素空一格
否则输出-1

Sample Input
3 3
1 2 3
4 5 6
7 8 9
3 3
1 2 3
4 5 6
7 8 9
Sample Output
0 0 0
0 0 0
0 0 0
HINT

Append Code
[Submit][Status]

*/
