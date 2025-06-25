#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n, m, l;
  cin >> n;
  vector<string> name(n);
  for (int i = 0; i < n; i++)
    cin >> name[i];
  cin >> m;
  vector<map<string, int> > s(m);
  vector<map<string, double> > ss(m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      s[i][name[j]] = 0, ss[i][name[j]] = 0;
  for (int i = 0; i < m; i++) {
    cin >> l;
    int max = 0;
    for (int j = 0; j < l; j++) {
      string ch;
      int g;
      cin >> ch >> g;
      s[i][ch] += g;
      if (max < g)
        max = g;
    }
    for (map<string, int>::iterator it = s[i].begin(); it != s[i].end(); it++) {
      if (max == 0)
        ss[i][it->first] = 0;
      else
        ss[i][it->first] = 100.0 * it->second / max;
    }
  }
  cout << "NAME        ";
  for (int i = 0; i < m; i++)
    cout << "TEST" << i + 1 << (i > 8 ? " " : "  ");
  cout << "FINAL" << endl;
  for (int i = 0; i < n; i++) {
    cout << setw(12) << setfill(' ') << left << name[i];
    for (int j = 0; j < m; j++)
      cout << setprecision(2) << fixed << setw(7) << ss[j][name[i]];
    double sum = 0;
    for (int j = 0; j < m; j++)
      sum += ss[j][name[i]];
    sum /= m;
    cout << setprecision(2) << fixed << setw(6) << sum;
    cout << endl;
  }
  return 0;
}
/*

Description

OJ是一个同学们又爱又恨的东东。老师在OJ上布置了作业，并且把作业成绩作为实验课程的成绩。马上就要结课了，小明想知道自己到底能得到多少分，所以他向老师请教分数的计算方法。老师告诉他，分数是这么算滴：

1. 对于某次作业，假设所有同学中Accpted题目数最多为X，小明Accpted题目数为Y，那么这次作业小明得分100Y/X。

2. 如果小明不幸错过了某次作业或者没有题目被Accpted，那么为0分。

3. 最终成绩是所有作业成绩的平均分。

好了，小明从OJ上下载了所有的standing，发现要想计算成绩还是挺麻烦的。所以，他向你求助，请你帮忙编个程序，算算分数。

Input

第1行N>0，表示本年级、本专业的学生数。

之后N行，每行是一个不含空白符的字符串，是一个学生的名字（假定没有重名，且姓名最多有10个字符）。

接着是M>0，表示老师总共布置的作业次数。

每次作业的输入中，第1行K>0，表示这次作业的standing中有提交记录的学生人数。之后K行是K个学生的姓名及其Accpted的题目数。

Output

第1行输出：NAME        TEST1  TEST2  TEST3 ...... FINAL。

其中，“TEST？”的个数等于作业次数，按照顺序依次输出，如上所示。

之后根据输入的专业学生姓名顺序，依次输出所有学生的每次作业成绩以及最终成绩。

所有输出左对齐。

成绩保留2位小数，且左对齐输出。

输出的每一列的第1个字符要对齐。

见样例。
Sample Input
5
zhangsan
lisi
wangwu
liuliu
dingqi
3
2
zhangsan 4
lisi 8
5
zhangsan 11
lisi 7
wangwu 4
liuliu 3
dingqi 4
3
zhangsan 3
lisi 10
wangwu 7
Sample Output
NAME        TEST1  TEST2  TEST3  FINAL
zhangsan    50.00  100.00 30.00  60.00
lisi        100.00 63.64  100.00 87.88
wangwu      0.00   36.36  70.00  35.45
liuliu      0.00   27.27  0.00   9.09
dingqi      0.00   36.36  0.00   12.12
HINT

Append Code
[Submit][Status]

*/
