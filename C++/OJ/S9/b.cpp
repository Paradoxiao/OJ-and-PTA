#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main() {
  deque<string> pipe;
  int ops;
  cin >> ops;
  for (int i = 0; i < ops; i++) {
    int op;
    string str;
    cin >> op;
    switch (op) {
    case 0:
      pipe.clear();
      break;
    case 1:
      cin >> str;
      pipe.push_front(str);
      break;
    case 2:
      cin >> str;
      pipe.push_back(str);
      break;
    case 3:
      if (pipe.empty())
        cout << -1 << endl;
      else
        cout << pipe.back() << endl;
      break;
    case 4:
      if (pipe.empty())
        cout << -1 << endl;
      else
        cout << pipe.front() << endl;
      break;
    case 5:
      if (pipe.empty())
        cout << -1 << endl;
      else
        pipe.pop_back();
      break;
    case 6:
      if (pipe.empty())
        cout << -1 << endl;
      else
        pipe.pop_front();
      break;
    }
  }
  return 0;
}
/*

Description

现在有一个管道，这个管道是垂直的可以容纳许多字符串。我们定义如下操作。

1.插入 将一个字符串压入管道中，新压入的字符串位于管道的最上方。

2.插入 将一个字符串压入管道中，新压入的字符串位于管道的最下方。

3.输出管道中最低端的字符串，如果管道为空，输出-1

4.输出管道中最高端的字符串，如果管道为空，输出-1

5.将最低端的字符串删除，删除之后原来位于第二低的字符串到了最低端，如果管道为空，输出-1

6.将最高端的字符串删除，删除之后原来位于第二高的字符串到了最高端，如果管道为空，输出-1

0.将管道清空

Input

第一行为一个整数Q 不超过1000

之后Q行 每行首先一个整数 代表操作 0～6 分别对应三种操作

如果操作为一 之后跟随一个字符串 只包含小写字母

Output

每一个2操作输出相应的答案

Sample Input
3
1 a
2 b
3
Sample Output
b
HINT

你可以使用STL中的deque很轻易的完成这个问题。

Append Code
[Submit][Status]

*/
