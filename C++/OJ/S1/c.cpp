#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class SpecialPrime {
  static bool is_prime(int n) {
    if (n < 2)
      return 0;
    if (n == 2)
      return 1;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0)
        return 0;
    return 1;
  }
  static bool is_special(int n) {
    char num[100];
    sprintf(num, "%d", n);
    for (char *p = num, *q = num + strlen(num) - 1; p < q; p++, q--)
      if (*p != *q)
        return 0;
    return 1;
  }

public:
  static bool judge(int n) {
    return is_prime(n) && is_special(n);
    // if (n < 2)
    //   return 0;
    // if (n == 2)
    //   return 1;
    // for (int i = 2; i * i <= n; i++)
    //   if (n % i == 0)
    //     return 0;
    // char num[100];
    // sprintf(num, "%d", n);
    // for (char *p = num, *q = num + strlen(num) - 1; p < q; p++, q--)
    //   if (*p != *q)
    //     return 0;
    // return 1;
  }
};
int main() {
  int m, n, i;
  cin >> m >> n;
  for (i = m; i < n; i++) {
    if (SpecialPrime::judge(i))
      cout << i << endl;
  }
  return 0;
}

/*

Description

定义一个类SpecialPrime，只有一个静态成员函数

bool judge(int value)

用于判断value是否是一个回文素数。所谓回文素数是指一个数既是回文数又是素数。
Input

输入两个数m和n，0<m<n。
Output

区间[m,n]内的所有回文素数。
Sample Input
2 1000
Sample Output
2
3
5
7
11
101
131
151
181
191
313
353
373
383
727
757
787
797
919
929
HINT

Append Code
append.cc,
[Submit][Status]

*/