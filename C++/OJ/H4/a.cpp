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
/*

Description

目前，汽车的能源主要有油类燃料动力（包括汽油、柴油）、电动力两种。现在定义三个类：

1. Car类，包括静态整型数据成员cntOfCars，用于记录产生的汽车对象的个数。一个double型属性，表示汽车的速度。定义其构造和析构函数，其中输出信息见样例。

2. OilCar类，是Car类的子类，包括静态整型数据成员cntOfOilCars，记录产生的燃油动力汽车对象的个数。一个double类型的属性，表示汽车百公里油耗。定义其构造和析构函数，其中输出信息见样例。定义show()方法，用于输出如样例所示的信息。

3. ElecCar类，是Car类的子类，包括静态整型数据成员cntOfElecCars，记录产生的电动力汽车对象的个数。一个double类型的属性，表示汽车百公里能耗（以KW为单位）。定义其构造和析构函数，其中输出信息见样例。定义show()方法，用于输出如样例所示的信息。
Input

输入2行，每行包括2个double类型的正数。
Output

见样例。
Sample Input
100 8.32
80 199.35
Sample Output
The 1th car is created.
The 1th oil-car is created.
An oil-car at speed of 100km/s, with 8.32L/100km.
The 2th car is created.
The 1th electrical car is created.
An electrical car at speed of 80km/s, with 199.35KW/100km.
The 1th electrical car is erased.
The 2th car is erased.
The 1th oil-car is erased.
The 1th car is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/