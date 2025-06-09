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
  void output() const {
    if (!n) {
      cout << "[NULL]";
      return;
    }
    cout << "[";
    for (int i = 0; i < n; i++)
      cout << (i ? " " : "") << arr[i];
    cout << "]";
  }
  bool is_equal(const OrdSet &other) const {
    if (n != other.n)
      return 0;
    for (int i = 0; i < n; i++)
      if (arr[i] != other.arr[i])
        return 0;
    return 1;
  }
  bool is_subset(const OrdSet &other) const {
    if (n < other.n)
      return 0;
    for (int i = 0; i < other.n; i++)
      if (find(arr, arr + n, other.arr[i]) == arr + n)
        return 0;
    return 1;
  }
  bool is_proper_subset(const OrdSet &other) const {
    return is_subset(other) && !is_equal(other);
  }
};
void TestOrdSet(const OrdSet &lhs, const OrdSet &rhs) {
  if (lhs.is_equal(rhs)) {
    rhs.output();
    cout << " is equal to ";
    lhs.output();
    cout << "." << endl;
  }
  if (lhs.is_subset(rhs)) {
    rhs.output();
    cout << " is subset to ";
    lhs.output();
    cout << "." << endl;
  }
  if (lhs.is_proper_subset(rhs)) {
    rhs.output();
    cout << " is proper subset to ";
    lhs.output();
    cout << "." << endl;
  }
}

int main() {
  OrdSet os, oo;
  os.input();
  oo.input();
  TestOrdSet(os, oo);
  TestOrdSet(oo, os);
  return 0;
}