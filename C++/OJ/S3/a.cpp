#include <iostream>
using namespace std;
class Base {
protected:
  int data;

public:
  Base(int d) : data(d) {
    cout << "Base = " << data << " is created." << endl;
  }
  Base(const Base &other) : data(other.data) {
    cout << "Base = " << data << " is copied." << endl;
  }
  ~Base() {
    cout << "Base = " << data << " is erased." << endl;
  }
};
class Derived : public Base {
private:
  int derivedData;

public:
  Derived(int d1, int d2) : Base(d1), derivedData(d2) {
    cout << "Derived = " << derivedData << " is created." << endl;
  }
  Derived(const Derived &other) : Base(other), derivedData(other.derivedData) {
    cout << "Derived = " << derivedData << " is copied." << endl;
  }
  ~Derived() {
    cout << "Derived = " << derivedData << " is erased." << endl;
  }
};
int main() {
  int cases, data1, data2;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> data1 >> data2;
    Base base1(data1), base2(base1);

    Derived derived1(data1, data2), derived2(derived1);
  }
}