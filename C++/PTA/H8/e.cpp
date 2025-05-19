#include <cstdio>
#include <queue>
using namespace std;
int main() {
  int n, x;
  scanf("%d", &n);
  queue<int> a, b;
  bool not_first = false;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x % 2)
      a.push(x);
    else
      b.push(x);
  }
  while (!a.empty() || !b.empty()) {
    if (!a.empty()) {
      printf(not_first ? " %d" : "%d", a.front());
      not_first = true;
      a.pop();
    }
    if (!a.empty()) {
      printf(not_first ? " %d" : "%d", a.front());
      not_first = true;
      a.pop();
    }
    if (!b.empty()) {
      printf(not_first ? " %d" : "%d", b.front());
      not_first = true;
      b.pop();
    }
  }
  return 0;
}