/*#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    a %= b;
    if (a == 0) {
      cout << "0" << endl;
      continue;
    }
    map<int, int> pos;
    vector<int> digits;
    int idx = 0, repeat_start = -1;
    while (a && pos.find(a) == pos.end()) {
      pos[a] = idx++;
      a *= 10;
      digits.push_back(a / b);
      a %= b;
    }
    if (a == 0) {
      cout << "0" << endl;
    } else {
      repeat_start = pos[a];
      for (int i = repeat_start; i < digits.size(); ++i)
        cout << digits[i];
      cout << endl;
    }
  }
  return 0;
}*/
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  while (cin >> a >> b) {
    int rem[10005], pos[10005], digits[10005];
    int idx = 0, repeat_start = -1;
    a %= b;
    memset(pos, -1, sizeof(pos));
    while (a && pos[a] == -1) {
      pos[a] = idx;
      a *= 10;
      digits[idx++] = a / b;
      a %= b;
    }
    if (!a) {
      cout << "0" << endl;
    } else {
      repeat_start = pos[a];
      for (int i = repeat_start; i < idx; ++i)
        cout << digits[i];
      cout << endl;
    }
  }
  return 0;
}