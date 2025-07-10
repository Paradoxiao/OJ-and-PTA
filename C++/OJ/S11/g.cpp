#include <iostream>
#include <vector>
using namespace std;
class Appliance {
private:
  static double totalCost;
  double cost;

protected:
public:
  Appliance(double c) : cost(c) {
    totalCost += c;
    cout << "An appliance of cost= " << cost << " is created." << endl;
  }
  double getCost() const {
    return cost;
  }
  virtual ~Appliance() {
    cout << "An appliance of cost= " << cost << " is erased." << endl;
    totalCost -= cost;
  }
  static double getTotalCost() {
    return totalCost;
  }
};
double Appliance::totalCost = 0.0;
class AirConditioiner : public Appliance {
private:
  int horsePower;

protected:
public:
  AirConditioiner(double c, int hp) : Appliance(c), horsePower(hp) {
    cout << "An air-conditioner of horse-power= " << horsePower << " is created." << endl;
  }
  ~AirConditioiner() {
    cout << "An air-conditioner of horse-power= " << horsePower << " is erased." << endl;
  }
};
class Refrigerator : public Appliance {
private:
  int volume;

protected:
public:
  Refrigerator(double c, int v) : Appliance(c), volume(v) {
    cout << "A refrigerator of volume= " << volume << " is created." << endl;
  }
  ~Refrigerator() {
    cout << "A refrigerator of volume= " << volume << " is erased." << endl;
  }
};
class Room {
private:
  vector<Appliance *> appliances;

protected:
public:
  Room() {
    cout << "A room is created." << endl;
  }
  double getApplianceCost() {
    double total = 0;
    for (vector<Appliance *>::iterator it = appliances.begin(); it != appliances.end(); ++it)
      total += (*it)->getCost();
    return total;
  }
  virtual ~Room() {
    for (vector<Appliance *>::iterator it = appliances.begin(); it != appliances.end(); ++it)
      delete *it;
    cout << "A room is erased." << endl;
  }
  virtual void addAppliance(Appliance *a) {
    appliances.push_back(a);
  }
};
class BedRoom : public Room {
private:
protected:
public:
  BedRoom() {
    cout << "A bedroom is created." << endl;
  }
  ~BedRoom() {
    cout << "A bedroom is erased." << endl;
  }
  void addAppliance(Appliance *a) {
    AirConditioiner *ac = dynamic_cast<AirConditioiner *>(a);
    if (ac)
      Room::addAppliance(a);
    else
      throw 1;
  }
};
class Kitchen : public Room {
private:
protected:
public:
  Kitchen() {
    cout << "A kitchen is created." << endl;
  }
  ~Kitchen() {
    cout << "A kitchen is erased." << endl;
  }
  void addAppliance(Appliance *a) {
    Refrigerator *fridge = dynamic_cast<Refrigerator *>(a);
    if (fridge)
      Room::addAppliance(a);
    else
      throw 2;
  }
};
class Building {
private:
  vector<Room *> rooms;

protected:
public:
  Building() {
    cout << "A building is created." << endl;
  }
  ~Building() {
    for (vector<Room *>::iterator it = rooms.begin(); it != rooms.end(); ++it)
      delete *it;
    cout << "A building is erased." << endl;
  }
  void addRoom(Room *a) {
    rooms.push_back(a);
  }
  void printInfo() {
    cout << "The information of this building is:" << endl;
    cout << "It has " << rooms.size() << " rooms." << endl;
    int bedroomCount = 0, kitchenCount = 0;
    double bedroomCost = 0, kitchenCost = 0;
    for (vector<Room *>::iterator it = rooms.begin(); it != rooms.end(); ++it)
      if (dynamic_cast<BedRoom *>(*it))
        bedroomCount++, bedroomCost += (*it)->getApplianceCost();
      else if (dynamic_cast<Kitchen *>(*it))
        kitchenCount++, kitchenCost += (*it)->getApplianceCost();
    cout << "It has " << bedroomCount << " bedrooms, with appliances' cost of $" << bedroomCost << "." << endl;
    cout << "It has " << kitchenCount << " kitchens, with appliances' cost of $" << kitchenCost << "." << endl;
  }
};
int main() {
  int n, m, i, j;
  char roomType, appType;
  int vol, para;
  double cost;
  Building building;
  Room *rp;
  Appliance *ap;
  vector<Appliance *> wrongPlaces;
  vector<Appliance *>::iterator itr;
  cout << "Initially, the total cost of appliances is " << Appliance::getTotalCost() << "." << endl;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> roomType >> m;
    switch (roomType) {
    case 'b':
      rp = new BedRoom();
      break;
    case 'k':
      rp = new Kitchen();
      break;
    }
    for (j = 0; j < m; j++) {
      cin >> appType >> cost >> para;
      switch (appType) {
      case 'a':
        ap = new AirConditioiner(cost, para);
        break;
      case 'r':
        ap = new Refrigerator(cost, para);
        break;
      }
      try {
        rp->addAppliance(ap);
      } catch (int ex) {
        wrongPlaces.push_back(ap);
        if (ex == 1)
          cout << "A refrigerator cannot put in a bedroom." << endl;
        else if (ex == 2)
          cout << "An air-conditioner cannot put in a kitchen." << endl;
      }
    }
    building.addRoom(rp);
  }
  cout << "--------------------Beautiful Separator---------------------" << endl;
  building.printInfo();
  cout << "--------------------Beautiful Separator---------------------" << endl;
  cout << "Till now, the total cost of appliance is " << Appliance::getTotalCost() << "." << endl;
  for (itr = wrongPlaces.begin(); itr < wrongPlaces.end(); itr++)
    delete *itr;
  return 0;
}

/*

Description

一栋住宅楼（Buliding）由若干个房间（Room）组成，房间可以分为卧室（BedRoom）和厨房（Kitchen）。房间里可以有家电（Appliance），家电又分为空调（AirConditioner）和冰箱（Refrigerator）。

根据上述描述，定义上述7个类，需要实现：

1.Appliance类：有“价格”（cost）属性，且可以统计所有家电的总价。成员函数getTotalCost()用于获取所有家电的总价。

2. AirConditioiner类：Appliance的子类。有“匹数”（horse-power）属性。

3. Refrigerator类：Appliance的子类。有“容量”（volume）属性。

4.Room类：拥有若干家电。成员函数getApplianceCost()获取其中所有家电的总价。成员函数addAppliance(Appliance *a)用于将a添加到一个Room对象的家电列表中。

5. BedRoom类：Room的子类。成员函数addAppliance(Appliance *a)只能增加空调，如果增加冰箱，则抛出异常：整数1。

6.Kitchen类：Room的子类。成员函数addAppliance(Appliance *a)只能增加冰箱，如果增加空调，则抛出异常：整数2。

7.Building类：由若干个Room的对象组成的类。成员函数addRoom(Room *a)用于增加一个房间；成员函数printInfo()按照题目输出样例输出Building的信息。

上述类均有构造函数、析构函数，且有输出。输出格式参见样例。
Input

第1行是正整数N，表示有N个房间。

之后有N行，每行开头是一个字符“b”或“k”，其中“b”表示该行时一个卧室，“k”表示该行是一个厨房。接着是一个正整数M，表示后面有需要放入该房间的M个家电（注意：不一定可以放入）。后面的M组输入中，每组输入包括1个字母（“a”或“r”）、1个实数和1个整数，其中“a”表示对应的家电是空调，“r”表示对应的家电是冰箱，实数是该家电的价格，整数则表示家电的匹数（对于空调）或容量（对于冰箱）。
Output

按照题目要求产生输出。
Sample Input
2
b 2 a 1000 1 r 2000 100
k 2 a 2000 2 r 3000 400
Sample Output
A building is created.
Initially, the total cost of appliances is 0.
A room is created.
A bedroom is created.
An appliance of cost= 1000 is created.
An air-conditioner of horse-power= 1 is created.
An appliance of cost= 2000 is created.
A refrigerator of volume= 100 is created.
A refrigerator cannot put in a bedroom.
A room is created.
A kitchen is created.
An appliance of cost= 2000 is created.
An air-conditioner of horse-power= 2 is created.
An air-conditioner cannot put in a kitchen.
An appliance of cost= 3000 is created.
A refrigerator of volume= 400 is created.
--------------------Beautiful Separator---------------------
The information of this building is:
It has 2 rooms.
It has 1 bedrooms, with appliances' cost of $1000.
It has 1 kitchens, with appliances' cost of $3000.
--------------------Beautiful Separator---------------------
Till now, the total cost of appliance is 8000.
A refrigerator of volume= 100 is erased.
An appliance of cost= 2000 is erased.
An air-conditioner of horse-power= 2 is erased.
An appliance of cost= 2000 is erased.
A bedroom is erased.
An air-conditioner of horse-power= 1 is erased.
An appliance of cost= 1000 is erased.
A room is erased.
A kitchen is erased.
A refrigerator of volume= 400 is erased.
An appliance of cost= 3000 is erased.
A room is erased.
A building is erased.
HINT

Append Code
append.cc,
[Submit][Status]

*/
