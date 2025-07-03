#include <iostream>
using namespace std;
class Person {
protected:
  string name;

public:
  Person(string n) : name(n) {
    cout << "Person " << name << " is created." << endl;
  }
  Person(const Person &other) : name(other.name) {
    cout << "Person " << name << " is copied." << endl;
  }
  ~Person() {
    cout << "Person " << name << " is erased." << endl;
  }
};
class Director : public Person {
public:
  Director(string n) : Person(n) {
    cout << "Director " << name << " is created." << endl;
  }
  Director(const Director &other) : Person(other) {
    cout << "Director " << name << " is copied." << endl;
  }
  ~Director() {
    cout << "Director " << name << " is erased." << endl;
  }
};
class Actor : public Person {
public:
  Actor(string n) : Person(n) {
    cout << "Actor " << name << " is created." << endl;
  }
  Actor(const Actor &other) : Person(other) {
    cout << "Actor " << name << " is copied." << endl;
  }
  ~Actor() {
    cout << "Actor " << name << " is erased." << endl;
  }
};
class Film {
private:
  Director director;
  Actor actor;
  string title;

public:
  Film(string d, string a, string t) : director(d), actor(a), title(t) {
    cout << "Film " << title << " is created." << endl;
  }
  ~Film() {
    cout << "Film " << title << " is erased." << endl;
  }
};
int main() {
  string directorName, actorName, filmName;
  cin >> directorName >> actorName >> filmName;
  Person person(directorName);
  Director director(directorName);
  Actor actor(actorName);
  Film film(directorName, actorName, filmName);
  return 0;
}
/*

Description

将电影的组成简单化，一部电影包含1个导演、1个演员和1个电影名。定义如下类：Person、Director、Actor和Film，Person类只有一个属性name，表示姓名。Director和Acotr是Person类的子类。Film包含director、actor和name三个属性，分别表示导演、演员和电影名。根据给定的主函数和输入、输出，编写这4个类，达到题目要求的效果。
Input

三个字符串，每个字符串不含空白符。分别表示导演的名字、演员的名字和电影的名字。
Output

见样例。
Sample Input
ZhangYimao ZhangZiyi WoHuCangLong
Sample Output
Person ZhangYimao is created.
Person ZhangYimao is created.
Director ZhangYimao is created.
Person ZhangZiyi is created.
Actor ZhangZiyi is created.
Person ZhangYimao is created.
Director ZhangYimao is created.
Person ZhangZiyi is created.
Actor ZhangZiyi is created.
Film WoHuCangLong is created.
Film WoHuCangLong is erased.
Actor ZhangZiyi is erased.
Person ZhangZiyi is erased.
Director ZhangYimao is erased.
Person ZhangYimao is erased.
Actor ZhangZiyi is erased.
Person ZhangZiyi is erased.
Director ZhangYimao is erased.
Person ZhangYimao is erased.
Person ZhangYimao is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/