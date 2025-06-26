#include <iostream>
#include <string>
using namespace std;
int main() {
  string ch;
  cin >> ch;
  for (string::iterator i = ch.begin(), j = ch.end() - 1; i <= j; ++i, --j)
    if (*i != *j) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
/* NOTE: 根据屎题目要求

  // #include <stack>
  // #include <vector>
  // stack<char> s;
  // vector<char> v;
  // for (string::iterator it = ch.begin(); it != ch.end(); ++it)
  //   s.push(*it), v.push_back(*it);
  // for (vector<char>::iterator it = v.begin(); it != v.end(); ++it) {
  //   if (*it != s.top()) {
  //     cout << "NO" << endl;
  //     return 0;
  //   }
  //   s.pop();
  // }

*/

/*

Description

对于给定的一个字符串，判断是否是回文串。
Input

一个字符串。
Output

如果是一个回文串，则输出YES，否则输出NO。
Sample Input
chinanihc
Sample Output
YES
HINT

注意：

1. 不能使用数组，即程序中不能出现[、]和new。

2. 可以借助vector和stack判断。

Append Code
[Submit][Status]

*/
