#include <iostream>
#include <vector>
using namespace std;
class Array {
private:
  vector<int> data;

public:
  void input() {
    int n;
    cin >> n;
    data.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data[i];
  }
  void Complete() {
    for (int i = 0; i < data.size(); ++i)
      if (data[i] == -1) {
        int prev = i - 1, next = i + 1;
        while (prev >= 0 && data[prev] == -1)
          --prev;
        while (next < data.size() && data[next] == -1)
          ++next;
        if (prev >= 0 && next < data.size())
          data[i] = (data[prev] + data[next]) / 2;
      }
  }
  void output() {
    for (int i = 0; i < data.size(); ++i)
      cout << (i ? " " : "") << data[i];
    cout << endl;
  }
};
int main() {
  Array arr;
  arr.input();
  arr.Complete();
  arr.output();
  return 0;
}

/*

Description

进行数据采集时，经常由于各种外界环境影响，导致数据缺失，此时就需要进行数据补齐。假定所有正确的数据都是正整数，以-1表示缺失数据。在按照一个时间序列采集数据时，不存在连续的数据缺失，即采集的数据中不会出现多于1个的连续-1值；而且第一个和最后一个不会缺失。

现在需要编写一个类Array，对缺失的数据进行补齐。补齐的规则是用缺失数据的前后两个值的平均值的整数部分进行补齐。

Array中的input函数用于输入，output函数用于输出，Complete函数用于根据补齐规则进行补齐。
Input

输入一个正整数N>2，表示后面还有N个采集到的数据。之后是N个整数，其中正常数据为正整数，缺失数据为-1。
Output

补齐后的N个数据。两两之间用一个空格隔开。
Sample Input
5 1 2 -1 3 4
Sample Output
1 2 2 3 4
HINT

Append Code
append.cc,
[Submit][Status]

*/
