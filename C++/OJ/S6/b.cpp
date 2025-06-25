#include <iostream>
#include <string>
using namespace std;
class Person {
private:
protected:
  string name;

public:
  Person(string n) : name(n) {
    cout << "A person " << name << " is created." << endl;
  }
  virtual ~Person() {
    cout << "A person " << name << " is erased." << endl;
  }
};
class Student : virtual public Person {
private:
protected:
  int id;

public:
  Student(string n, int i) : Person(n), id(i) {
    cout << "A student " << id << " is created." << endl;
  }
  ~Student() {
    cout << "A student " << id << " is erased." << endl;
  }
};
class Teacher : virtual public Person {
private:
protected:
  double pay;

public:
  Teacher(string n, double p) : Person(n), pay(p) {
    cout << "A teacher " << pay << " is created." << endl;
  }
  ~Teacher() {
    cout << "A teacher " << pay << " is erased." << endl;
  }
};
class TeacherStudent : public Teacher, public Student {
private:
public:
  TeacherStudent(string n, int i, double p) : Person(n), Teacher(n, p), Student(n, i) {
    cout << "A teacher-student is created." << endl;
  }
  ~TeacherStudent() {
    cout << "A teacher-student is erased." << endl;
  }
};
int main() {
  string name;
  int id;
  double salary;
  Person *p;
  Teacher *t;
  Student *s;
  p = new TeacherStudent("tom", 10, 3300.22);
  t = new TeacherStudent("tom", 11, 3400.22);
  s = new TeacherStudent("tom", 12, 3500.22);
  cin >> name >> id >> salary;
  TeacherStudent ts2(name, id, salary);
  delete p;
  delete t;
  delete s;
  return 0;
}

/*

Description

定义Person类，只有一个“姓名”属性；定义Person类的子类Student和Teacher，分别增加属性“学号”和“工资”；定义Teacher和Student的子类TeacherStudent。定义它们的构造函数、析构函数，能够使main函数的运行得到规定的输出。
Input

一个不含空白符的字符串、一个正整数和一个实数。
Output

见样例。
Sample Input
Jack 101 3100.34
Sample Output
A person tom is created.
A teacher 3300.22 is created.
A student 10 is created.
A teacher-student is created.
A person tom is created.
A teacher 3400.22 is created.
A student 11 is created.
A teacher-student is created.
A person tom is created.
A teacher 3500.22 is created.
A student 12 is created.
A teacher-student is created.
A person Jack is created.
A teacher 3100.34 is created.
A student 101 is created.
A teacher-student is created.
A teacher-student is erased.
A student 10 is erased.
A teacher 3300.22 is erased.
A person tom is erased.
A teacher-student is erased.
A student 11 is erased.
A teacher 3400.22 is erased.
A person tom is erased.
A teacher-student is erased.
A student 12 is erased.
A teacher 3500.22 is erased.
A person tom is erased.
A teacher-student is erased.
A student 101 is erased.
A teacher 3100.34 is erased.
A person Jack is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/
