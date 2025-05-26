#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int>::iterator itr;
int main() {
  int num, sum = 0;
  while (cin >> num)
    arr.push_back(num);
  sort(arr.begin(), arr.end());
  for (itr = arr.begin(); itr != arr.end(); itr++)
    sum += *itr;
  cout << sum << endl;
  return 0;
}
