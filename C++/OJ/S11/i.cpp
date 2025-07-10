#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
class RLE {
private:
  string str;

protected:
public:
  RLE(string s, char t) : str(s) {
    if (t == 'c')
      decoder();
    else if (t == 'p')
      encoder();
  }
  string decoder() {
    string result;
    for (int i = 0; i < str.size(); ++i) {
      char ch = str[i];
      ++i;
      int count = 0;
      while (i < str.size() && isdigit(str[i]))
        count = count * 10 + (str[i] - '0'), ++i;
      --i;
      result.append(count, ch);
    }
    return result;
  }
  string encoder() {
    string result;
    for (int i = 0; i < str.size(); ++i) {
      char ch = str[i];
      int count = 1;
      while (i + 1 < str.size() && str[i + 1] == ch)
        ++count, ++i;
      result += ch;
      char countStr[10];
      sprintf(countStr, "%d", count);
      result += countStr;
    }
    return result;
  }
};
int main() {
  string str;
  char ch;
  while (cin >> ch >> str) {
    RLE rle(str, ch);
    if (ch == 'p')
      cout << rle.encoder() << endl;
    else
      cout << rle.decoder() << endl;
  }
}

/*

Description

RLE是一种无损压缩算法。假设一段文本是由26个英文字母组成的，RLE压缩算法的基本原理是，统计连续的相同字母的个数，用该字母及其出现的次数来代替原文进行压缩。如：

原文：aaaabbbbbbcccd

压缩为：a4b6c3d1

编写类RLE，包括：

1.RLE(string str,char t)：t为“p”时，表示str是原文；t为“c”时，表示str是压缩后的串。

2.encoder()：计算原文压缩后的串，并返回。

3.decoder()：计算压缩串解压后的原文，并返回。
Input

输入有若干行，每行包括一个字母和一个不含空白符的字符串。字母为“p”，则字符串为原文；字母为“c”，则字符串为压缩后的串。
Output

每行输入对应一行输出。如果输入的是原文，则输出压缩后的串；如果输入的是压缩后的串，则输出原文。
Sample Input
p aaaabbbbbbcccd
c a4b6c3d1
Sample Output
a4b6c3d1
aaaabbbbbbcccd
HINT

Append Code
append.cc,
[Submit][Status]

*/
