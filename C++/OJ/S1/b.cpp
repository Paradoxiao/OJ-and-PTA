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