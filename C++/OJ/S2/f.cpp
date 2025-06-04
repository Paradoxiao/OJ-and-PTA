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