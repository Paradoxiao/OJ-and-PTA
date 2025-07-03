#include <iostream>
#include <string>
using namespace std;
class Thesis {
  string author;
  string name;
  string school;
  string type;
  int date[3];

public:
  void input() {
    getline(cin, author);
    getline(cin, name);
    getline(cin, school);
    for (int i = 0; i < 3; i++)
      cin >> date[i];
    cin >> type;
  }
  void output() {
    if (type == "b")
      type = "Bachelor";
    if (type == "m")
      type = "Master";
    if (type == "d")
      type = "Doctor";
    cout << author << ";" << name << ";" << school << ";";
    for (int i = 0; i < 3; i++) {
      cout << date[i] << (i < 2 ? "-" : "");
    }
    cout << ";" << type << endl;
  }
};
int main() {
  Thesis thesis;
  thesis.input();
  thesis.output();
  return 0;
}
/*

Description

从普通本科开始，一个正常毕业的学生会依次获得学士、硕士、博士学位。现在需要定义一个类Thesis，记录授予学位的如下信息：

1.学生姓名；

2.论文名；

3.学校名；

4.授予日期；

5.学位类型。

请根据给定的main函数，定义类及其方法input和output。
Input

输入有5行。

第1行是学生姓名。

第2行是毕业论文名。

第3行是学校名。

第4行是按照年、月、日格式给出的日期。

第5行是一个字符。其中b表示Bachelor，m表示Master，d表示Doctor。
Output

输出只有一行，使用分号作为分隔符，输出的上述5个信息。其中日期按照年、月、日顺序输出，并用短划线隔开。学位输出Bachelor、Master、Doctor之一。
Sample Input
Zhang San
Design and Implementation of Management system
Shandong University of Science and Technology
2024 9 8
b
Sample Output
Zhang San;Design and Implementation of Management system;Shandong University of Science and Technology;2024-9-8;Bachelor
HINT

1.C++中，可以使用getline函数输入一行字符（含空白符）；

2.C++中，可以使用类string来定义字符串。需包含头文件string。

Append Code
append.cc,
[Submit][Status]

*/