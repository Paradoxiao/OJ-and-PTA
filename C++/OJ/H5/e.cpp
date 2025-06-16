#include <iostream>
#include <string>
using namespace std;
class Student {
protected:
  string name;
  bool sex;
  int grade;
  Student *next;

public:
  Student(string name, bool sex, int grade) : name(name), sex(sex), grade(grade), next(NULL) {
    cout << "A student named by " << name << " is created!" << endl;
  }
  Student *getNext() {
    return next;
  }
  ~Student() {
    cout << "A student named by " << name << " is erased." << endl;
  }
  void showInfo() {
    cout << "name = " << name << ", sex = " << sex << ", grade = " << grade << ";";
  }
  void setNext(Student *nextStudent) {
    next = nextStudent;
  }
};
class StudentCadre : public Student {
private:
  string position;

public:
  StudentCadre(string name, bool sex, int grade, string position) : Student(name, sex, grade), position(position) {
    cout << "A student cadre with position " << position << " is created." << endl;
  }
  void showInfo() {
    cout << "name = " << name << ", sex = " << sex << ", grade = " << grade << "; position = " << position << ".";
  }
};
int main() {
  int num;
  string name, position;
  bool sex;
  int grade;
  Student *header, *student, *curStudent;

  cin >> name >> sex >> grade >> position;
  header = new StudentCadre(name, sex, grade, position);
  curStudent = header;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> name >> sex >> grade;
    student = new Student(name, sex, grade);
    curStudent->setNext(student);
    curStudent = curStudent->getNext();
  }
  ((StudentCadre *)header)->showInfo();
  cout << endl;
  curStudent = header;
  while (curStudent->getNext() != NULL) {
    curStudent = curStudent->getNext();
    curStudent->showInfo();
    cout << endl;
  }

  curStudent = header;
  while (curStudent != NULL) {
    student = curStudent;
    curStudent = curStudent->getNext();
    delete student;
  }
  return 0;
}
