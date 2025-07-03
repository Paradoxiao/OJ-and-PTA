#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n) {
    multiset<int> stamps;
    for (int i = 0; i < n; ++i) {
      string op;
      cin >> op;
      if (op == "B") {
        int value;
        cin >> value;
        stamps.insert(value);
      } else if (op == "G")
        if (!stamps.empty()) {
          multiset<int>::iterator it = stamps.begin();
          cout << *it << endl;
          stamps.erase(it);
        }
    }
    cin >> n;
  }
  return 0;
}
/*

Description
小明是个邮票迷，整天乐衷于邮票收集。他对每张邮票都有一个喜爱程度，用一个正整数来表示，整数越大代表小明越喜欢这张邮票，小明经常购买邮票来丰富他的收藏。
有时候小明的朋友会来和小明要邮票，于是小明每次就给他最不喜欢的一张。这是个麻烦的工作，小明听说你最近学习了multiset，你能帮他解决吗？

Input
有多组输入数据，对于每个数据，有一个整数n（1<n<=20）,接下来n行，每行只有以下两种格式之一：
“B S”，代表小明买了一张喜欢程度为S的邮票
“G” 代表小明的朋友问小明要邮票。
n=0代表输入结束。

Output
对于每次输入“G”，你要输出小明给了朋友邮票的喜好程度。

Sample Input
8
B 20
B 10
G
B 9
G
B 100
B 25
G
0
Sample Output
10
9
20
HINT

用STL的multiset容易解决

Append Code
[Submit][Status]

*/
