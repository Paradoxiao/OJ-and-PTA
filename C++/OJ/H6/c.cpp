#include <iostream>
#include <set>
using namespace std;
int main() {
  set<int> a, b;
  int num;
  while (cin >> num) {
    a.clear();
    b.clear();
    while (num != 0) {
      a.insert(num);
      cin >> num;
    }
    cin >> num;
    while (num != 0) {
      b.insert(num);
      cin >> num;
    }
    if (a == b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
/*

Description
最近Jerry正在刻苦的学习STL中的set的功能函数，他发现set可以用现有的函数实现并、交、差、对称差等功能，但是他没有找到怎么来比较两个集合是否相等的功能函数，所以他想自己用其他的功能函数来实现能判断两个集合是否相等的功能函数。聪明的Jerry不一会就想到了解决办法，现在他想拿这道题来考考你，看你有没有他聪明。

Input

输入有多组，每组数据有两行，每一行都代表一个集合，每一行有若干个正整数(0<d<=2147483647)，并且每行的最后一个数字都是0,代表该行数据的结束，且末尾的0不计入集合中。最后以EOF结束输入。

Output
对于每组数据输出都要输入一个结果，如果两个集合相等便输出“YES”，否则输出“NO”，每个结果占一行

Sample Input
1 2 3 4 0
1 2 3 4 0
1 2 2 2 2 2 0
1 2 0
1 2 3 4 0
1 3 3 4 0
Sample Output
YES
YES
NO
HINT

对称差运算：得到的结果是第一个集合与第二个集合的差集并上第二个与第一个的差集


Append Code
[Submit][Status]

*/
