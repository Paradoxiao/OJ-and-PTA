#include <iostream>
using namespace std;
class Data {
private:
  int data;

public:
  Data(int data) : data(data) {
    cout << "Data " << data << " is created." << endl;
  }
  Data() {
    cout << "Data's default constructor." << endl;
  }
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
  Data data[10];

public:
  DataArray(int *a) {
    for (int i = 0; i < 10; i++)
      data[i].setValue(a[i]);
  }
  DataArray() {
    cout << "DataArray's default constructor." << endl;
  }
  ~DataArray() {
    cout << "DataArray's deconstructor." << endl;
  }
  void setValues(int *a) {
    for (int i = 0; i < 10; i++)
      data[i].setValue(a[i]);
  }
  int getSum() {
    int sum = 0;
    for (int i = 0; i < 10; i++)
      sum += data[i].getValue();
    return sum;
  }
};
int main() {
  DataArray dataArray;
  Data *aData;
  int data[10], tmp;
  int i;
  for (i = 0; i < 10; i++) {
    cin >> data[i];
  }
  dataArray.setValues(data);
  cout << "Sum is " << dataArray.getSum() << endl;

  cin >> tmp;
  aData = new Data(tmp);
  cout << "aData = " << aData->getValue() << endl;
  delete aData;
  return 0;
}
