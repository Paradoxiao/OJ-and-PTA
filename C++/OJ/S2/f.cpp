#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
  string name;
  bool hasName;

public:
  Person() {
    cout << "A person without name is created." << endl;
    hasName = false;
  }
  Person(string n) {
    name = n;
    hasName = true;
    cout << "Person " << name << " is created." << endl;
  }
  virtual ~Person() {
    if (hasName)
      cout << "Person " << name << " is erased." << endl;
    else
      cout << "A person without name is erased." << endl;
  }
};
class Teacher : public Person {
private:
  string position;

public:
  Teacher(string n, string p) : Person(n) {
    position = p;
    hasName = true;
    cout << "Teacher " << name << " " << position << " is created." << endl;
  }
  ~Teacher() {
    cout << "Teacher " << name << " is erased." << endl;
  }
};
class Student : public Person {
private:
  double score;

public:
  Student(string n, double s) : Person(n) {
    score = s;
    hasName = true;
    cout << "Student " << name << " " << score << " is created." << endl;
  }
  ~Student() {
    cout << "Student " << name << " is erased." << endl;
  }
};
int main() {
  string name, pos;
  double sco;
  cin >> name >> pos >> sco;
  Person person;
  Person *p;
  p = new Teacher(name, pos);
  delete p;
  Person *q;
  q = new Student(name, sco);
  delete q;
  return 0;
}
/*

Description

一个简单的教务系统中的用户至少包含学生、老师两类用户。两类用户都有共同的属性姓名，教师有特有的属性职称，学生有特有的属性成绩。根据给出的主函数、输入和输出，定义三个类Person、Teacher和Student，实现基本的构造和析构功能。
Input

只有一行。第1个和第2个是字符串，表示姓名、职称，第3个是一个实数，表示成绩。
Output

见样例。
Sample Input
Tom Prof 234
Sample Output
A person without name is created.
Person Tom is created.
Teacher Tom Prof is created.
Teacher Tom is erased.
Person Tom is erased.
Person Tom is created.
Student Tom 234 is created.
Student Tom is erased.
Person Tom is erased.
A person without name is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/