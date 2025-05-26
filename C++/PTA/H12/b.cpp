#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int weight;
  int parent;
  int lchild;
  int rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;

#include <algorithm>
void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2) {
  s1 = s2 = 0;
  for (int i = 1; i <= upbound; i++)
    if (HT[i].parent == 0) {
      if (s1 == 0 || HT[i].weight < HT[s1].weight) {
        s2 = s1;
        s1 = i;
      } else if (s2 == 0 || HT[i].weight < HT[s2].weight) {
        s2 = i;
      }
    }
}
using namespace std;
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) {
  HT = (HTNode *)malloc((2 * n) * sizeof(HTNode));
  for (int i = 1; i <= n; i++) {
    HT[i].weight = w[i - 1];
    HT[i].parent = 0;
    HT[i].lchild = 0;
    HT[i].rchild = 0;
  }
  int big, small, size = n;
  while (size < 2 * n - 1) {
    SelectTwoMin(size++, HT, small, big);
    HT[small].parent = size;
    HT[big].parent = size;
    HT[size] = {HT[small].weight + HT[big].weight, 0, small, big};
  }
  HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
  char num[n];
  for (int i = 1; i <= n; i++) {
    HC[i] = (char *)malloc(n * sizeof(char));
    int c = 0, j = i;
    while (HT[j].parent != 0) {
      if (HT[HT[j].parent].lchild == j)
        num[c++] = '0';
      else
        num[c++] = '1';
      j = HT[j].parent;
    }
    num[c] = '\0';
    reverse(num, num + c);
    strcpy(HC[i], num);
  }
  for (int i = 1; i <= n; i++) {
    if (HC[i][0] == '\0') {
      HC[i][0] = '0';
      HC[i][1] = '\0';
    }
  }
}

int main() {
  HuffmanTree ht;
  HuffmanCode hc;

  int n;
  scanf("%d", &n);

  int *w = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i)
    scanf("%d", &w[i]);

  HuffmanCoding(ht, hc, w, n);

  for (int i = 1; i <= 2 * n - 1; ++i) {
    printf("%d %d %d %d\n", ht[i].weight, ht[i].parent, ht[i].lchild,
           ht[i].rchild);
  }

  for (int i = 1; i <= n; ++i)
    printf("%s\n", hc[i]);

  free(w);
  free(ht);
  for (int i = 1; i <= n; ++i)
    free(hc[i]);

  return 0;
}
/* 你的代码将被嵌在这里 */
