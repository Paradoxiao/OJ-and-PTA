#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Word {
private:
protected:
  string str;

public:
  Word(string s) : str(s) {}
  virtual ~Word() {};
  virtual bool isIllegal() = 0;
};
class Keyword : public Word {
private:
  static vector<string> mykeymaps;

protected:
public:
  Keyword(string s) : Word(s) {}
  bool isIllegal() {
    for (int i = 0; i < mykeymaps.size(); ++i)
      if (str == mykeymaps[i])
        return true;
    return false;
  }
  void getKeywords() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      string keyword;
      cin >> keyword;
      mykeymaps.push_back(keyword);
    }
  }
};
vector<string> Keyword::mykeymaps;
class UserDefined : public Word {
private:
protected:
public:
  UserDefined(string s) : Word(s) {}
  bool isIllegal() {
    Keyword keyword(str);
    if (keyword.isIllegal())
      return false;
    if (str.empty() || isdigit(str[0]))
      return false;
    for (int i = 0; i < str.size(); ++i)
      if (!isalnum(str[i]) && str[i] != '_')
        return false;
    return true;
  }
};
class Integer : public Word {
private:
protected:
public:
  Integer(string s) : Word(s) {}
  bool isIllegal() {
    if (str.empty())
      return false;
    for (int i = 0; i < str.size(); ++i)
      if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
        return false;
    return true;
  }
};
int main() {
  Word *word;
  char k;
  string str;
  Keyword keyword("");
  keyword.getKeywords();
  while (cin >> k >> str) {
    switch (k) {
    case 'k':
      word = new Keyword(str);
      break;
    case 'u':
      word = new UserDefined(str);
      break;
    case 'i':
      word = new Integer(str);
      break;
    }
    if (word->isIllegal())
      cout << "Right." << endl;
    else
      cout << "Error." << endl;
    delete word;
  }
  return 0;
}

/*

Description

程序是由单词（Word）组成的，单词可以分为关键字、用户自定义标识符以及文字常量等。对于输入的不同字符串，编程判断属于哪一类单词。需要编写的类有：

1.Word类：用于描述单词的抽象类。成员函数isIllegal()是一个纯虚函数。

2.Keyword类：Word类的子类，用于判断一个字符串是否是关键字。成员函数getKeywords()用于读取所有的关键字。

3.UserDefined类：Word类的子类，用于判断一个字符串是否是合法的用户自定义标识符。

4.Integer类：Word类的子类，用于判断一个字符串是否是一个整型常量（不限制取值范围）。
Input

输入有多行，第1行是一个正整数n，表示关键字个数。第2行是n个字符串，表示n个关键字。之后的若干行，每行包括1个字符和1个字符串，其中字符“k”表示后面要跟一个关键字，字符“u”表示后面要跟一个用户自定义标识符，字符“i”表示后面要跟一个整数。所有字符串都不含空白符。
Output

除第1行和第2行输入外，其他每行输入对应1行输出。如果对应输入行的字符串属于相应字符表示的类型，则输出“Right.”，否则输出“Error.”。
Sample Input
5
int double float for if
k int
u int
u Int
i 321
i -983
i 143d

Sample Output
Right.
Error.
Right.
Right.
Right.
Error.
HINT

Append Code
append.cc,
[Submit][Status]

*/
