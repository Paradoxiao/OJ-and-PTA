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