#include <iostream>
using namespace std;
class Car {
protected:
  static int cntOfCars;
  double speed;

public:
  Car(double speed) : speed(speed) {
    cout << "The " << ++cntOfCars << "th car is created." << endl;
  }
  ~Car() {
    cout << "The " << cntOfCars-- << "th car is erased." << endl;
  }
};
class OilCar : public Car {
private:
  static int cntOfOilCars;
  double oil;

public:
  OilCar(double speed, double oil) : Car(speed), oil(oil) {
    cout << "The " << ++cntOfOilCars << "th oil-car is created." << endl;
  }
  ~OilCar() {
    cout << "The " << cntOfOilCars-- << "th oil-car is erased." << endl;
  }
  void show() {
    cout << "An oil-car at speed of " << speed << "km/s, with " << oil << "L/100km." << endl;
  }
};
class ElecCar : public Car {
private:
  static int cntOfElecCars;
  double power;

public:
  ElecCar(double speed, double power) : Car(speed), power(power) {
    cout << "The " << ++cntOfElecCars << "th electrical car is created." << endl;
  }
  ~ElecCar() {
    cout << "The " << cntOfElecCars-- << "th electrical car is erased." << endl;
  }
  void show() {
    cout << "An electrical car at speed of " << speed << "km/s, with " << power << "KW/100km." << endl;
  }
};
int Car::cntOfCars = 0, OilCar::cntOfOilCars = 0, ElecCar::cntOfElecCars = 0;
int main() {
  double power, oil, speed;
  cin >> speed >> oil;
  OilCar one(speed, oil);
  one.show();
  cin >> speed >> power;
  ElecCar two(speed, power);
  two.show();
  return 0;
}