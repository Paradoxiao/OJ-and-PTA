#include <cstdio>
using namespace std;
struct LNode {
  int data;
  LNode *next;
  LNode(int data) : data(data), next(nullptr) {}
};
struct S {
  LNode *topNode;
  S() : topNode(nullptr) {}
  void push(int data) {
    LNode *temp = new LNode(data);
    temp->next = topNode;
    topNode = temp;
  }
  void pop() {
    if (!topNode)
      return;
    LNode *temp = topNode;
    topNode = topNode->next;
    delete temp;
  }
  bool empty() {
    return topNode == nullptr;
  }
  int top() {
    return topNode->data;
  }
};
int main() {
  S data;
  int N, n, i = 0;
  scanf("%d", &N);
  scanf("%d", &n);
  while (n >= 0) {
    data.push(n);
    scanf("%d", &n);
  }
  for (i = N - 1; i > 0 && !data.empty(); i--)
    data.pop();
  if (data.empty()) {
    puts("NULL");
    return 0;
  }
  printf("%d", data.top());
  return 0;
  return 0;
}
/*#include <cstdio>
#include <stack>
using namespace std;
int main() {
  stack<int> data;
  int N, n, i = 0;
  scanf("%d", &N);
  scanf("%d", &n);
  while (n >= 0) {
    data.push(n);
    scanf("%d", &n);
  }
  for (i = N - 1; i > 0 && !data.empty(); i--)
    data.pop();
  if (data.empty()) {
    puts("NULL");
    return 0;
  }
  printf("%d", data.top());
  return 0;
}*/