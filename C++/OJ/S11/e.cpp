#include <iostream>
#include <vector>
using namespace std;
class Mark {
private:
  vector<int> scores;
  vector<double> weights;

protected:
public:
  void input() {
    int n;
    cin >> n;
    scores.resize(n), weights.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> scores[i];
    for (int i = 0; i < n; ++i)
      cin >> weights[i];
  }
  double getFinalMark() {
    double finalMark = 0.0;
    for (size_t i = 0; i < scores.size(); ++i)
      finalMark += scores[i] * weights[i];
    return finalMark;
  }
};
int main() {
  Mark mark;
  mark.input();
  cout << mark.getFinalMark() << endl;
  return 0;
}

/*

Description

一门课程的成绩是由若干部分组成的，每部分占总成绩的一部分。定义类Mark，根据给定的各部分成绩计算最终的总成绩。

总成绩为各部分成绩乘以相应权重的和。

Mark类的input函数用于根据要求输入各部分成绩及权重。

Mark类的getFinalMark函数用于求总成绩。
Input

输入有3行，第一行是一个整数N>2，表示总成绩由N部分成绩组成。

第2行包括N个实数，是N个部分的成绩。

第3行包含N个实数，是N个部分的权重。

两行的输入顺序相同。
Output

总成绩。
Sample Input
4
60 60 60 60
0.2 0.3 0.3 0.2
Sample Output
60
HINT

Append Code
append.cc,
[Submit][Status]

*/
