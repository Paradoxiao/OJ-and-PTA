#include <iostream>
using namespace std;
class Pear {
  double pear_weight;

public:
  Pear(double w = 0) : pear_weight(w) {
    cout << pear_weight << "kg pear is created." << endl;
  }
  ~Pear() {
    cout << pear_weight << "kg pear is erased." << endl;
  }
  Pear(const Pear &p) : pear_weight(p.pear_weight) {
    cout << pear_weight << "kg pear is copied." << endl;
  }
  double weight() const {
    return pear_weight;
  }
  void weight(double w) {
    pear_weight = w;
  }
};
int main() {
  double w;
  cin >> w;
  Pear pe(w), pea, pear(pe);
  cin >> w;
  pear.weight(w);
  cout << pear.weight() << endl;
}