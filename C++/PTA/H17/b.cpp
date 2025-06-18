

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int n; // 皇后个数
bool place(int k, int i, int *x);
void nQueens(int k, int n, int *x);

int main() {

  cin >> n;
  int *x = new int[n + 1];
  if (n == 2 || n == 3)
    cout << "0" << endl;
  nQueens(0, n, x);

  return 0;
}

/* 请在这里填写答案 */

void nQueens(int k, int n, int *x) {
  for (int i = 0; i < n; i++)
    if (place(k, i, x)) {
      x[k] = i;
      if (k == n - 1) {
        for (i = 0; i < n; i++)
          cout << x[i] << " ";
        cout << endl;
      } else
        nQueens(k + 1, n, x);
    }
}

bool place(int k, int i, int *x) {
  if (k == 0)
    return true;
  int j = 0;
  while (j < k) {
    if ((x[j] == i) || (abs(x[j] - i) == abs(k - j)))
      return false;
    j++;
  }
  return true;
}
