#include <iostream>
using namespace std;
class Book {
private:
  string name;
  double price;

public:
  Book(char n[], double p) {
    name = n;
    price = p;
    cout << "A book " << name << " is created." << endl;
  }
  Book() {
    cout << "A default book is created." << endl;
  }
  ~Book() {
    cout << "A book " << name << " is erased." << endl;
  }
  void setName(string n) {
    name = n;
  }
  void setPrice(double p) {
    price = p;
  }
  double getPrice() {
    return price;
  }
  string getName() {
    return name;
  }
};
int main() {
  Book books[4] = {Book("C++", 42.0)};
  string tmp;
  double sum, price;
  int i;
  for (i = 0; i < 3; i++) {
    cin >> tmp >> price;
    books[i + 1].setName(tmp);
    books[i + 1].setPrice(price);
  }
  sum = 0;
  for (i = 0; i < 4; i++) {
    sum += books[i].getPrice();
  }
  cout << "The four books are: " << books[0].getName();
  for (i = 1; i < 4; i++) {
    cout << " " << books[i].getName();
  }
  cout << endl << "Their total price is " << sum << endl;
  return 0;
}
