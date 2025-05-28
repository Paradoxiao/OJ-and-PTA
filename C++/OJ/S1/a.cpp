#include <iostream>
using namespace std;
class Integer {
  unsigned long long data;

public:
  void input() {
    cin >> data;
  }
  bool isOdd() {
    return data % 2;
  }
  bool isPrime() {
    if (data < 2)
      return 0;
    if (data == 2)
      return 1;
    for (int i = 2; i * i < data; i++)
      if (data % i == 0)
        return 0;
    return 1;
  }
};
int main() {
  Integer data;
  data.input();
  if (data.isOdd()) {
    cout << "It is an odd number." << endl;
  } else {
    cout << "It is an even number." << endl;
  }
  if (data.isPrime()) {
    cout << "It is a prime." << endl;
  } else {
    cout << "It is not a prime." << endl;
  }
  return 0;
}