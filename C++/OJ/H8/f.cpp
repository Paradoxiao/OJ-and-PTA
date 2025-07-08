#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
  int n;
  int num;
  std::vector<int> arr;
  std::vector<int>::iterator it;
  std::cin >> n;
  while (std::cin >> num)
    arr.push_back(num);
  it = std::find(arr.begin(), arr.end(), n);
  std::string ans;
  if (it != arr.end())
    ans = "Yes";
  else
    ans = "No";
  std::cout << ans << std::endl;
  return 0;
}

/*

Description
给程序添加合适的头文件，使其能运行起来，并得出正确结果。程序代码见“Append Code”。
         C++万能头文件被禁用。

Input
         输入为n个数字，表示成绩。

Output
         按顺序输出成绩的等级，错误数据输出“error”

Sample Input
5
10 20 30 40 50
Sample Output
No
HINT

Append Code
append.c, append.cc,
[Submit][Status]

*/
