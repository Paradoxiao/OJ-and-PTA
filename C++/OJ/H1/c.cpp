#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n) {
    vector<int> num(n);
    for (int i = 0; i < n; i++)
      cin >> num[i];
    int max = num[0], min = num[0];
    for (int i = 1; i < n; i++) {
      if (num[i] > max)
        max = num[i];
      if (num[i] < min)
        min = num[i];
    }
    cout << max << " " << min << endl;
    cin >> n;
  }
  return 0;
}