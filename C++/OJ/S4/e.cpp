#include <iostream>
using namespace std;
class Student {
private:
  int age;
  string name;

public:
  friend istream &operator>>(istream &is, Student &other) {
    is >> other.name >> other.age;
    return is;
  }
  friend ostream &operator<<(ostream &os, const Student &other) {
    os << other.name << " " << other.age;
    return os;
  }
  bool operator>(const Student &other) {
    if (age > other.age)
      return true;
    if (age < other.age)
      return false;
    return name > other.name;
  }
};
int main() {
  Student stu, max;
  while (cin >> stu) {
    if (stu > max)
      max = stu;
  }
  cout << max << endl;
  return 0;
}

/*

Description

定义一个类Student，拥有属性age（int类型）和name（字符串），重载其大于、输出和输入运算符。大于运算符比较的规则是先比较年龄，年龄大的对象为大；如果年龄相同，则比较姓名，姓名大的对象为大。

编程用于求输入的若干个学生的最大者。
Input

输入有若干行，每行包括一个字符串（无空白符）、一个整数，分别学生的姓名name和年龄age。
Output

最大学生的信息。格式见样例。
Sample Input
Tom 20
Jack 18
Tom 19
Jack 21
Sample Output
Jack 21
HINT

*/
