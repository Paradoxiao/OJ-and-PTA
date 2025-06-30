#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student {
private:
  pair<int, string> data;

protected:
public:
  bool operator<(const Student &other) const {
    return data < other.data;
  }
  friend istream &operator>>(istream &is, Student &other) {
    is >> other.data.second >> other.data.first;
    return is;
  }
  friend ostream &operator<<(ostream &os, const Student &other) {
    os << other.data.second << " " << other.data.first;
    return os;
  }
};
class StudentGroup {
private:
  vector<Student> data;

protected:
public:
  void add(Student s) {
    data.push_back(s);
  }
  void srt() {
    sort(data.begin(), data.end());
  }
  void show() {
    for (int i = 0; i < data.size(); i++)
      cout << data[i] << endl;
  }
};
int main() {
  Student stu, max;
  StudentGroup stuG;
  while (cin >> stu) {
    if (!(stu < max))
      max = stu;
    stuG.add(stu);
  }
  stuG.srt();
  stuG.show();
  cout << "The max is " << max << endl;
  return 0;
}

/*

Description

输入若干个学生的姓名和年龄，将他们排序后输出，并求输入的若干个学生的最大者。

定义一个类Student，拥有属性age（int类型）和name（字符串），重载其小于、输出和输入运算符。小于运算符比较的规则是先比较年龄，年龄大的对象为大；如果年龄相同，则比较姓名，姓名大的对象为大。

基于Student类定义类StudentGroup，该类有若干个学生组成，定义其add方法、srt方法和show方法，用于增加1个学生、对所有的学生排序和显示所有的学生信息。
Input

输入有若干行，每行包括一个字符串（无空白符）、一个整数，分别学生的姓名name和年龄age。
Output

先按照学生比较规则按照递增序输出所有学生信息，每个学生信息占一行。最后一行输出最大学生的信息，格式见样例。
Sample Input
Tom 19
Jack 21
Mary 20
Tom 22
Jack 13
Sample Output
Jack 13
Tom 19
Mary 20
Jack 21
Tom 22
The max is Tom 22
HINT

Append Code
append.cc,
[Submit][Status]

*/
