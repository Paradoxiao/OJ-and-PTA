#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  unsigned long long n, m, a, b, sum = 0;
  cin >> n;
  priority_queue<unsigned long long, vector<unsigned long long>,
                 greater<unsigned long long>>
      q;
  for (int i = 0; i < n; i++) {
    cin >> m;
    q.push(m);
  }
  while (q.size() > 1) {
    a = q.top();
    q.pop();
    b = q.top();
    q.pop();
    sum += a + b;
    q.push(a + b);
  }
  cout << sum;
  return 0;
}