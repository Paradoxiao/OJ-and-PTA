#include <iostream>
using namespace std;
class MyString {
private:
  char ch[105];

protected:
public:
  friend istream &operator>>(istream &is, MyString &other) {
    is >> other.ch;
    return is;
  }
  int operator[](char c) {
    static int i = -1;
    while (ch[++i] != '\0')
      if (ch[i] == c)
        return i;
    return -1;
  }
};
int main() {
  MyString mystr;
  char c;
  int pos;
  cin >> mystr >> c;
  do {
    pos = mystr[c];
    cout << pos << endl;
  } while (pos != -1);
  return 0;
}

/*

Description

定义类MyString，由长度不超过100的字符串组成。重载其下标运算符：

int operator[](char ch)

用于重复求指定字符ch在串中的下标。

重载其输入运算符，用于输入字符串。
Input

输入一个不含空白符的字符串（长度不超过100个）和一个字符。
Output

指定字符在字符串中的所有位置。
Sample Input
babababaab a
Sample Output
1
3
5
7
8
-1
HINT

下标运算符中需要用到静态变量。

禁止使用STL，包括list、vector和string等。

Append Code
append.cc,
[Submit][Status]

*/
