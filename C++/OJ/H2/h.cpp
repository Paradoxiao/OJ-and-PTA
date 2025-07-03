#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int>::iterator itr;
int main() {
  int num, sum = 0;
  while (cin >> num)
    arr.push_back(num);
  sort(arr.begin(), arr.end());
  for (itr = arr.begin(); itr != arr.end(); itr++)
    sum += *itr;
  cout << sum << endl;
  return 0;
}
/*

Description

给程序添加合适的头文件，使其能运行起来，并得出正确结果。程序代码见“Append Code”。C++万能头文件被禁用。

Input

输入若干整数。

Output

求和并输出。

Sample Input
5 2 1 3 4
Sample Output
15
HINT

Append Code
append.cc,
[Submit][Status]

*/