#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num[n];
  for (auto &i : num)
    cin >> i;
  sort(num, num + n);
  for (int i = 0; i < n; i++)
    cout << (i ? " " : "") << num[i];
  return 0;
}
