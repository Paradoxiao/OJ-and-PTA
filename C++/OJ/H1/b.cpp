#include <iostream>
#include <string>
using namespace std;
int main() {
  string s, num = "";
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] >= '0' && s[i] <= '9')
      num += s[i];
  if (num == "")
    cout << "null" << endl;
  else
    cout << num << endl;
  return 0;
}