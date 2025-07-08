#include <iostream>
#include <string>
using namespace std;
class Score {
private:
  double score;

protected:
public:
  Score(double score) : score(score) {}
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
  cin >> n;

  while (n--) {
    double num;
    cin >> num;
    Score score(num);
    cout << score.grade() << " " << score.print() << endl;
  }

  const Score score(60);
  cout << score.grade() << " " << score.print() << endl;
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
         按顺序输出成绩的等级和分数，错误数据输出“error”

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
B 89
C 70
D 65
E 32
E 0
D 60
HINT

Append Code
append.cc,
[Submit][Status]

*/
