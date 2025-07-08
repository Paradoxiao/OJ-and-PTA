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
class Course {
private:
  string _name;
  Score _score;

protected:
public:
  Course(string name, double score) : _name(name), _score(score) {}
  string name() {
    return _name;
  }
  Score score() {
    return _score;
  }
};
int main() {
  int n;
  cin >> n;

  while (n--) {
    double score;
    string name;
    cin >> name >> score;
    Course course(name, score);
    cout << course.name() << " " << course.score().grade() << endl;
  }
  return 0;
}

/*

Description
         用一些浮点数字表示百分制成绩，转换成五级制的成绩。其中，按小数点后第一位四舍五入为整数，满足下列个分数段要求：
         E：0～60分以下；
         D：60～70分以下；
         C：70～80分以下；
         B：80~90分以下；
         A：90～100分；
         不在0～100分之间的数字，是错误数据。
         输入一些课程名和成绩，输出课程的成绩等级。
用C++编写Course类和Score类来完成代码，调用格式见“Append Code”。

Input
         输入为n行，每行一个课程名和成绩。

Output
         输出课程及其成绩等级。

Sample Input
6
Mathematics 100
Chinese 89
English 70
Physics 65
Chemistry 32
Biology 0
Sample Output
Mathematics A
Chinese B
English C
Physics D
Chemistry E
Biology E
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
