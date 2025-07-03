#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
  multiset<int> s;
  int n;
  while (cin >> n && n) {
    s.clear();
    for (int i = 0; i < n; i++) {
      string op;
      int x;
      cin >> op >> x;
      if (op == "i")
        s.insert(x);
      else if (op == "d") {
        multiset<int>::iterator it = s.find(x);
        if (it != s.end())
          s.erase(it);
      }
    }
    for (multiset<int>::iterator it = s.begin(); it != s.end(); ++it)
      cout << (it != s.begin() ? " " : "") << *it;
    cout << endl;
  }
  return 0;
}
/*

Description

给你一个集合，一开始集合是空集，然后进行若干操作，最后你要从小到大输出集合中的元素，以空格隔开。（集合中可能会有相同元素）

Input
一共有若干输入数据，开头一个n（n<=20），n=0代表输入结束。
然后有n行，每行有2种形式：
“i x”，x是一个整数，代表向集合中插入元素x
“d x”，x是一个整数，代表删除一个x

Output
每组输入结束后，从小到大输出集合中的元素，以空格隔开。

Sample Input
2
i 2
i 2
4
i 1
i 1
i 2
d 1
0
Sample Output
2 2
1 2
HINT

用STL的multiset容易解决

Append Code
[Submit][Status]

*/
