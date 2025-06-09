#include <cstddef>
#include <iostream>
using namespace std;
class Car {
protected:
  static int cntOfCars;
  double speed;

public:
  Car(double speed = 0) : speed(speed) {
    cout << "The " << ++cntOfCars << "th car is created." << endl;
  }
  ~Car() {}
};
class OilCar : public Car {
private:
  static int cntOfOilCars;
  double oil;

public:
  OilCar(double speed = 0, double oil = 0) : Car(speed), oil(oil) {
    cout << "The " << ++cntOfOilCars << "th oil-car is created." << endl;
  }
  ~OilCar() {}
  void show() {
    cout << "An oil-car at speed of " << speed << "km/s, with " << oil << "L/100km." << endl;
  }
  void change(double s, double o) {
    speed = s, oil = o;
  }
};
class ElecCar : public Car {
private:
  static int cntOfElecCars;
  double power;

public:
  ElecCar(double speed = 0, double power = 0) : Car(speed), power(power) {
    cout << "The " << ++cntOfElecCars << "th electrical car is created." << endl;
  }
  ~ElecCar() {}
  void show() {
    cout << "An electrical car at speed of " << speed << "km/s, with " << power << "KW/100km." << endl;
  }
  void change(double s, double p) {
    speed = s, power = p;
  }
};
int Car::cntOfCars = 0, OilCar::cntOfOilCars = 0, ElecCar::cntOfElecCars = 0;
class CarHall {
private:
  OilCar *oil_car;
  ElecCar *ele_car;
  int cnt_oil, cnt_ele;

public:
  CarHall() : oil_car(NULL), ele_car(NULL), cnt_oil(0), cnt_ele(0) {}
  void getInfo() {
    int n;
    double a, b;
    cin >> n;
    oil_car = new OilCar[n];
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      oil_car[cnt_oil++].change(a, b);
    }
    cin >> n;
    ele_car = new ElecCar[n];
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      ele_car[cnt_ele++].change(a, b);
    }
  }
  void showInfo() {
    cout << "We have " << cnt_oil << " oil-cars, which are:" << endl;
    for (int i = 0; i < cnt_oil; i++)
      oil_car[i].show();
    cout << "We have " << cnt_ele << " electrical cars, which are:" << endl;
    for (int i = 0; i < cnt_ele; i++)
      ele_car[i].show();
  }
};
int main() {
  Car car;
  OilCar oilcar;
  ElecCar eleccar;
  CarHall carhall;
  carhall.getInfo();
  carhall.showInfo();
  return 0;
}