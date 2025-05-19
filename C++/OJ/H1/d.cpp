#include <iostream>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++)
    if (a[i] >= 'a' && a[i] <= 'z')
      a[i] += 'A' - 'a';
  for (int i = 0; i < b.length(); i++)
    if (b[i] >= 'a' && b[i] <= 'z')
      b[i] += 'A' - 'a';
  cout << (a == b ? "yes" : "no");
  return 0;
}