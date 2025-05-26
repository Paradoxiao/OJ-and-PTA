#include <iostream>
using namespace std;
class Data {
private:
  double data;

public:
  void init(double d) {
    data = d;
  }
  double getValue() {
    return data;
  }
  void showValue() {
    cout << data << endl;
  }
};
int main() {
  Data data;
  double d;
  cin >> d;
  data.init(d);
  cout << data.getValue() << endl;
  data.showValue();
}
