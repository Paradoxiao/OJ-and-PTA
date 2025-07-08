#include <iostream>
#include <istream>
#include <string>
#include <vector>
using namespace std;
class Score {
private:
  double _score;

protected:
public:
  Score(double score = 0) : _score(score) {}
  bool illegal() {
    return _score < 0 || _score > 100;
  }
  bool operator>(const Score &other) {
    return _score > other._score;
  }
  bool operator<(const Score &other) {
    return _score < other._score;
  }
  void input() {
    cin >> _score;
  }
  double print() const {
    return _score;
  }
  double score() const {
    return _score;
  }
  string grade() const {
    if (_score < 0 || _score > 100)
      return "error";
    if (_score < 60)
      return "E";
    if (_score < 70)
      return "D";
    if (_score < 80)
      return "C";
    if (_score < 90)
      return "B";
    return "A";
  }
  friend istream &operator>>(istream &is, Score &other) {
    is >> other._score;
    return is;
  }
};
class Course {
private:
  string _name;
  Score _score;

protected:
public:
  Course(string name = "", double score = 0) : _name(name), _score(score) {}
  string name() {
    return _name;
  }
  double score() {
    return _score.score();
  }
  void input() {
    cin >> _name >> _score;
  }
};
template <typename T>
class Array {
private:
  vector<T> data;

protected:
public:
  Array() : data(1000) {}
  T &operator[](int i) {
    return data[i];
  }
};
int main() {
  int i;

  int n;
  cin >> n;
  Array<Score> sco_arr;
  double sum_sco = 0;
  for (i = 0; i < n; i++) {
    sco_arr[i].input();
    sum_sco += sco_arr[i].score();
  }

  int m;
  cin >> m;
  Array<Course> cur_arr;
  double sum_cur = 0;
  for (i = 0; i < m; i++) {
    cur_arr[i].input();
    sum_cur += cur_arr[i].score();
  }

  cout << sum_sco / n << " " << Score(sum_sco / n).grade() << endl;
  cout << sum_cur / m << " " << Score(sum_cur / m).grade() << endl;

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
         要求你写一个模板数组类Array类，能够统计数据的平均值。
用C++编写Array类、Course类和Score类来完成代码，调用格式见“Append Code”。

Input
         输入两部分。首先为一个数字n，后接n行成绩。然后是一个数字m，后接m行课程名及其成绩。

Output
         输出n个成绩的平均值及其等级和m个课程成绩的平均值及其等级。

Sample Input
6
100
89
70
65
32
0
9
Mathematics 100
Chinese 89
English 70
Physics 65
Chemistry 32
Biology 0
Music 92
Geography 73
Art 79
Sample Output
59.3333 E
66.6667 D
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
