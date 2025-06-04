#include <iostream>
using namespace std;
class Data {
private:
  int data;

public:
  Data() : data(0) {
    cout << "Data's default constructor." << endl;
  }
  Data(int n) : data(n) {}
  ~Data() {
    cout << "Data " << data << " is erased." << endl;
  }
  int getValue() {
    return data;
  }
  void setValue(int n) {
    data = n;
  }
};
class DataArray {
private:
  Data *data;
  int n;

public:
  DataArray(int n, int *p) : n(n) {
    data = new Data[n];
    for (int i = 0; i < n; i++)
      data[i].setValue(p[i]);
    cout << "DataArray's constructor." << endl;
  };
  ~DataArray() {
    delete[] data;
    cout << "DataArray's deconstructor." << endl;
  }
  int getSum() {
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += data[i].getValue();
    return sum;
  }
};
int main() {
  int i, n;
  Data test, *testP;
  cin >> n;
  int tmp[n];
  for (i = 0; i < n; i++)
    cin >> tmp[i];
  DataArray datas(n, tmp);
  cout << "Sum is " << datas.getSum() << endl;
  testP = new Data;
  cin >> n;
  testP->setValue(n);
  delete testP;
  return 0;
}
