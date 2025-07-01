#include <iostream>
using namespace std;

#define P 13

typedef struct HashNode {
  int key;
  struct HashNode *next;
} HashNode, *HashTable;

void CreateHash(HashTable HT[], int n);
float ASL(HashTable HT[]);

int main() {
  int i, n;
  HashTable HT[P];
  for (i = 0; i < P; i++)
    HT[i] = NULL;
  cin >> n;
  CreateHash(HT, n);
  cout << ASL(HT);
  return 0;
}
/* 请在这里填写答案 */
void CreateHash(HashTable HT[], int n) {
  for (int _ = 0; _ < n; _++) {
    int data;
    cin >> data;
    if (!HT[data % P])
      HT[data % P] = new HashNode{data, nullptr};
    else if (!HT[data % P]->next)
      HT[data % P]->next = new HashNode{data, nullptr};
    else {
      HashTable newNode = new HashNode{data, HT[data % P]->next};
      HT[data % P]->next = newNode;
    }
  }
}
float ASL(HashTable HT[]) {
  float n = 0, sum = 0;
  for (int i = 0; i < P; i++)
    if (HT[i]) {
      int cnt = 1;
      n++, sum += cnt;
      HashTable p = HT[i]->next;
      while (p)
        n++, cnt++, p = p->next, sum += cnt;
    }
  return sum / n;
}
/*
Sample Input:
12
19 14 23 1 68 20 84 27 55 11 10 79
Sample Output:
1.75
HINT
*/
