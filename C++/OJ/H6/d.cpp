#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValid(string s) {
  stack<char> c;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      c.push(s[i]);
      continue;
    }
    if (s[i] == ')') {
      if (c.empty())
        return false;
      c.pop();
    }
  }
  return c.empty();
}
int main() {
  string s;
  stack<char> c;
  while (getline(cin, s)) {
    if (isValid(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
/*

Description
给出一堆括号，看其是否匹配，例如 ()、()()、(()) 这样的括号就匹配，
      )(、)()) 而这样的括号就不匹配

Input
每一行代表一组测试样例，每组测试样例只包含'('和')'，样例长度不超过100个字符

Output
如果所有的括号都匹配，那么输出YES，否则输出NO

Sample Input
()
)(
Sample Output
YES
NO
HINT

使用STL的stack容易实现。

Append Code
[Submit][Status]

*/
/*

Description
给出一堆括号，看其是否匹配，例如 ()、()()、(()) 这样的括号就匹配，
      )(、)()) 而这样的括号就不匹配

Input
每一行代表一组测试样例，每组测试样例只包含'('和')'，样例长度不超过100个字符

Output
如果所有的括号都匹配，那么输出YES，否则输出NO

Sample Input
()
)(
Sample Output
YES
NO
HINT

使用STL的stack容易实现。

Append Code
[Submit][Status]

*/
