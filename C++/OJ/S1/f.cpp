#include <cstdio>
#include <iostream>
using namespace std;
class Solve {
  double a, b, c, rate, quick;
  void calcTax() {
    if (a <= 36000) {
      rate = 0.03;
      quick = 0;
      return;
    }
    if (a <= 144000) {
      rate = 0.10;
      quick = 2520;
      return;
    }
    if (a <= 300000) {
      rate = 0.20;
      quick = 16920;
      return;
    }
    if (a <= 420000) {
      rate = 0.25;
      quick = 21920;
      return;
    }
    if (a <= 660000) {
      rate = 0.30;
      quick = 52920;
      return;
    }
    if (a <= 960000) {
      rate = 0.35;
      quick = 85920;
      return;
    }
    {
      rate = 0.45;
      quick = 181920;
      return;
    }
  }

public:
  Solve(double a, double c) : a(a), c(c) {}
  void printResult() {
    calcTax();
    b = a * rate - quick;
    if (b < c - 1e-6) {
      printf("Drawback %.2f.\n", c - b);
      return;
    }
    if (b - c <= 400 + 1e-6) {
      printf("No operation.\n");
      return;
    }
    {
      printf("Supplement %.2f.\n", b - c);
    }
  }
};

int main() {
  double A, C;
  while (cin >> A >> C) {
    Solve solve(A, C);
    solve.printResult();
  }
}
/*

Description

一个简易的计算个人收入应纳税额的办法是：根据全年应纳税金额A，确定税率R和速算扣除数K，应纳税额为：

B=A*R-K。

编写类Solve，对于输入一个人年度收入应纳税金额A、已经缴税金额C，计算年度汇算结果。有三种情况：

1.B<C，则退税C-B。

2.0<=B-C<=400，则不需要补缴。

3.B-C>400，需要补缴差额。

其中，税率和速算扣除数为：

级数
	

全年应纳税所得额
	

税率
	

速算扣除算

1
	

<=36000
	

3%
	

0

2
	

<=144000
	

10%
	

2520

3
	

<=300000
	

20%
	

16920

4
	

<=420000
	

25%
	

21920

5
	

<=660000
	

30%
	

52920

6
	

<=960000
	

35%
	

85920

7
	

>960000
	

45%
	

181920
Input

A和C，为实数。
Output

如果退税，显示“Drawback”和金额。如果不需要补缴也不需要退税，显示“No operation.”。如果需要补缴，则显示“Supplement”和金额。
Sample Input
36000 0
144000 1000
300000 1000
420000 1000
660000 1000
960000 1000
1000000 500000
Sample Output
Supplement 1080.00.
Supplement 10880.00.
Supplement 42080.00.
Supplement 82080.00.
Supplement 144080.00.
Supplement 249080.00.
Drawback 231920.00.
HINT

Append Code
append.cc,
[Submit][Status]

*/