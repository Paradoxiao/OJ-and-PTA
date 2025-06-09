#include <algorithm>
#include <iostream>
using namespace std;
class OrdSet {
private:
  int *arr, n;

public:
  OrdSet() : arr(NULL), n(0) {}
  void input() {
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    sort(arr, arr + n);
    n = unique(arr, arr + n) - arr;
  }
  void output() {
    if (!n) {
      cout << "[NULL]" << endl;
      return;
    }
    cout << "[";
    for (int i = 0; i < n; i++)
      cout << (i ? " " : "") << arr[i];
    cout << "]";
  }
};
int main() {
  OrdSet os;
  os.input();
  os.output();
  return 0;
}