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
