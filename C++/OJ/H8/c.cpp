#include <iostream>
#include <string>
using namespace std;
class Score {
private:
  double score;

protected:
public:
  Score(double score = 0) : score(score) {}
  bool illegal() {
    return score < 0 || score > 100;
  }
  bool operator>(const Score &other) {
    return score > other.score;
  }
  bool operator<(const Score &other) {
    return score < other.score;
  }
  void input() {
    cin >> score;
  }
  double print() const {
    return score;
  }
  string grade() const {
    if (score < 0 || score > 100)
      return "error";
    if (score < 60)
      return "E";
    if (score < 70)
      return "D";
    if (score < 80)
      return "C";
    if (score < 90)
      return "B";
    return "A";
  }
};
int main() {
  int n;
  Score score, max_score(0), min_score(100);
  cin >> n;
  while (n--) {
    score.input();
    if (score.illegal())
      continue;
    if (score > max_score)
      max_score = score;
    if (score < min_score)
      min_score = score;
  }
  cout << max_score.grade() << " " << max_score.print() << endl;
  cout << min_score.grade() << " " << min_score.print() << endl;
  return 0;
}

/*

Description
         输入一些浮点数字表示百分制成绩，转换成五级制的成绩。其中，各等级满足下列分数段划分要求：：
         E：0～60分以下；
         D：60～70分以下；
         C：70～80分以下；
         B：80~90分以下；
         A：90～100分；
         不在0～100分之间的数字，是错误数据。
用C++编写Score类来完成代码，调用格式见“Append Code”。

Input
         输入为n个数字，表示成绩。

Output
         按所有成绩中（不包括错误数据）的最大和最小成绩及其等级。

Sample Input
6
100
89
70
65
32
0
Sample Output
A 100
E 0
HINT

Append Code
append.cc,
[Submit][Status]

*/
