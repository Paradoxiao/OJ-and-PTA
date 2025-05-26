#include <stdio.h>
#include <stdlib.h>
struct Heap {
  int *data;
  int capacity;
  int size;
};
struct Heap *initHeap(int capacity) { // 初始化堆
  struct Heap *h;
  h = (struct Heap *)malloc(sizeof(struct Heap));
  if (!h)
    return NULL;
  h->data = (int *)malloc(sizeof(int) * capacity + 1);
  if (h->data == NULL) {
    free(h);
    return NULL;
  }
  h->capacity = capacity;
  h->size = 0;
  return h;
};
void printHeap(struct Heap *h) { // 打印堆元素
                                 /* 细节省略 */
}
int insertIntoHeap(struct Heap *h, int x) {
  if (h->size >= h->capacity)
    return 0;
  int i = h->size++;
  while (i > 1 && h->data[i / 2] > x) {
    h->data[i] = h->data[i / 2];
    i /= 2;
  }
  h->data[i] = x;
  return 1;
}

int deleteMin(struct Heap *h, int *pElement) {
  if (h->size == 0)
    return 0;
  *pElement = h->data[1];
  int last = h->data[h->size--];
  int parent = 1, child;
  while (parent * 2 <= h->size) {
    child = parent * 2;
    if (child != h->size && h->data[child + 1] < h->data[child])
      child++;
    if (last <= h->data[child])
      break;
    h->data[parent] = h->data[child];
    parent = child;
  }
  h->data[parent] = last;
  return 1;
}
int main() {
  struct Heap *h;
  int n;
  scanf("%d", &n); // 输入堆容量
  h = initHeap(n);
  int op, x;
  scanf("%d", &op);
  while (op) { // 输入操作： -1表示删除   1表示插入   0表示结束
    if (op == 1) {
      scanf("%d", &x);
      printf("Insertion %s. ", insertIntoHeap(h, x) ? "succeeded" : "failed");
      printHeap(h);
    } else {
      if (deleteMin(h, &x))
        printf("%d deleted. ", x);
      else
        printf("Deletion failed. ");
      printHeap(h);
    }
    scanf("%d", &op);
  }
  return 0;
}

/*你提交的代码将被嵌在这里 */