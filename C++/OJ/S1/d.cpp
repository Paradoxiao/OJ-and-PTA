#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class MyString {
  char s[1100];
  bool echo() {
    for (char *p = s, *q = s + strlen(s) - 1; p < q; p++, q--)
      if (*p != *q)
        return 0;
    return 1;
  }

public:
  void input() {
    scanf("%s", s);
  }
  void output() {
    int len = strlen(s);
    if (echo())
      s[len / 2 + (len % 2 ? 1 : 0)] = '\0';
    printf("%s\n", s);
  }
};
int main() {
  MyString str;
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    str.input();
    str.output();
  }
  return 0;
}
/*

Description
定义MyString类，包括：
1. 一个字符数组或字符指针，用于存储字符串内容。
2. void input()：读取一个不含空白符的字符串。
3. void output()：输出字符串。如果字符串不是回文串，则输出原串。如果是回文串，则仅输出前半部分。如：
原串：abccba，则输出abc
原串：abcdcba，则输出abcd
原串：abcd，则输出abcd

Input
第一行是整数N>0，表示之后有N个测试用例。每个测试用例占一行，是一个不含空白符的字符串。每个串不超过1000个字符。

Output

见样例。

Sample Input
4
abcdcba
abccba
abcdefgh
aaaaaaaa
Sample Output
abcd
abc
abcdefgh
aaaa
HINT

Append Code
append.cc,
[Submit][Status]

*/