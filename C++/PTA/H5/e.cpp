#include <cstdio>
using namespace std;
struct LNode {
  int data;
  LNode *next;
  LNode(int data) : data(data), next(nullptr) {}
};
class L {
public:
  LNode *cur;
  L() : cur(nullptr) {}
  void add(int data) {
    LNode *temp = cur;
    cur = new LNode(data);
    cur->next = temp;
  }
  void del() {
    LNode *temp = cur;
    cur = cur->next;
    delete temp;
  }
  bool emp() {
    return cur == nullptr;
  }
  void input() {
    int n;
    scanf("%d", &n);
    while (n >= 0) {
      add(n);
      scanf("%d", &n);
    }
  }
};
int main() {
  L a;
  int n;
  scanf("%d", &n);
  if (n < 1) {
    puts("NULL");
    return 0;
  }
  a.input();
  for (; n > 1 && !a.emp(); n--)
    a.del();
  if (!a.emp()) {
    printf("%d", a.cur->data);
    return 0;
  }
  puts("NULL");
  return 0;
}