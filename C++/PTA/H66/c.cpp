#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, m, size;
  bool pass;
  string ops;
  cin >> n >> m;
  while (n--) {
    cin >> ops;
    size = 0;
    pass = 1;
    for (char i : ops) {
      if (i == 'S' && ++size > m) {
        pass = 0;
        break;
      }
      if (i == 'X' && --size < 0) {
        pass = 0;
        break;
      }
    }
    if (size)
      pass = 0;
    cout << (pass ? "YES\n" : "NO\n");
  }
  return 0;
}