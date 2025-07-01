#include <iostream>
using namespace std;

#define m 16
#define NULLKEY 0 // 单元为空的标记

struct HashTable {
  int key;
};

void CreateHash(HashTable HT[], int n);  // 输入不大于m的n个不为0（0表示空值）的数，用线性探查法解决冲突构造散列表
int SearchHash(HashTable HT[], int key); // 输入一个值key，在散列表中查找key位置

int main() {
  int value, key;
  int result;
  int i, j, n;
  HashTable HT[m];
  for (i = 0; i < m; i++)
    HT[i].key = 0;
  cin >> n;
  if (n > m)
    return 0;
  CreateHash(HT, n);
  cin >> key;
  result = SearchHash(HT, key);
  if (result != -1)
    cout << "search success，The key is located in " << result + 1;
  else
    cout << "search failed";
  return 0;
}

/* 请在这里填写答案 */
void CreateHash(HashTable HT[], int n) {
  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    if (HT[data % m].key == NULLKEY)
      HT[data % m].key = data;
    else
      for (int j = 0; j < m; j++)
        if (HT[j].key == NULLKEY) {
          HT[j].key = data;
          break;
        }
  }
}
int SearchHash(HashTable HT[], int key) {
  if (HT[key % m].key == key)
    return key % m;
  for (int j = 0; j < m; j++)
    if (HT[j].key == key)
      return j;
  return -1;
}
/*
Sample Input:
12
19 14 23 1 68 20 84 27 55 11 10 79
55
Sample Output:
search success，The key is located in 6
HINT
*/
