#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++)
    cin >> s[i];
  sort(s, s + n);
  for (int i = 0; i < n; i++)
    cout << s[i] << endl;
  return 0;
}
/*

Description
    对N个字符串排序。
    0<N<=50000。每个字符串长度不超过50000,所有字符串长度总和不超过1000000。

Input
    第一行读入N。
    后面N行，每行一个字符串(只包含字母)。

Output

    输出共N行，按字典序从小到大输出。

Sample Input
5
bcdef
qwer
tyuiphdjf
asdfghjklzzzz
z
Sample Output
asdfghjklzzzz
bcdef
qwer
tyuiphdjf
z
HINT

用STL的string容易解决。

Append Code
[Submit][Status]

*/
