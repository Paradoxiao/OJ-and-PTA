#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b) {
  return a > b;
}
class Solve {
private:
  int *ji, *ou, j, k, n;

public:
  void input() {
    j = 0, k = 0;
    cin >> n;
    ji = new int[n / 2 + 2];
    ou = new int[n / 2 + 2];
    for (int i = 0; i < n; i++)
      if (i % 2)
        cin >> ji[j++];
      else
        cin >> ou[k++];
  }
  void sort() {
    std::sort(ji, ji + j);
    std::sort(ou, ou + k, cmp);
  }
  void output() {
    j = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (i != 0)
        cout << " ";
      if (i % 2)
        cout << ji[j++];
      else
        cout << ou[k++];
    }
  }
};
int main() {
  Solve solve;
  solve.input();
  solve.sort();
  solve.output();
  return 0;
}