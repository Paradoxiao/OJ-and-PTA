#include <cstdio>
using namespace std;
class Solve {
private:
  int n;

public:
  Solve(int num) : n(num) {}
  void printSolution() {
    bool not_first = 0;
    bool found = false;
    for (int i = 100; 2 * i <= n; ++i) {
      int rev = (i % 10) * 100 + ((i / 10) % 10) * 10 + (i / 100);
      if (i + rev == n && rev > 100) {
        printf(not_first ? ";%d-%d" : "%d-%d", i, rev);
        found = true;
        not_first = true;
      }
    }
    puts(found ? "" : "No answer.");
  }
};
int main() {
  int num, order = 0;
  while (scanf("%d", &num) != EOF) {
    Solve solve(num);
    printf("Case %d : ", ++order);
    solve.printSolution();
  }
  return 0;
}

/*

Description

设a、b、c都是一位数，它们的组合abc和cba是两个三位数，对于给定的sum，输出满足和为sum的abc和cba，要求同一对数不重复输出。根据题目要求和给定的main函数，编写相应的Solve类。
Input

输入有若干行，每行一个整数。
Output

每行输入对应一行输出，每行首先输出“Case # : ”，其中“#”为从1开始的测试用例编号。然后输出对应测试用例的结果，每对数按照“abc-cba”的格式输出，如果有多对数满足条件，则按照第1个数从小到大的顺序输出，且两两之间用一个分号分开；如果没有满足条件的解，则输出“No answer.”。
Sample Input
111
222
333
444
555
666
Sample Output
Case 1 : No answer.
Case 2 : 111-111
Case 3 : No answer.
Case 4 : 123-321;222-222
Case 5 : No answer.
Case 6 : 135-531;234-432;333-333
HINT

Append Code
append.cc,
[Submit][Status]

*/