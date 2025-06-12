#include <stdio.h>
#define MVNum 10
#define MaxInt 32767

typedef struct {
  char vexs[MVNum];
  int arcs[MVNum][MVNum];
  int vexnum, arcnum;
} AMGraph;

struct Evode {
  char Head;
  char Tail;
  int lowcost;
} Edge[(MVNum * (MVNum - 1)) / 2];

int Vexset[MVNum];
void CreateUDN(AMGraph &G); // 实现细节隐藏
void Kruskal(AMGraph G);
int LocateVex(AMGraph, char);
int main() {
  AMGraph G;
  CreateUDN(G);
  Kruskal(G);
  return 0;
}
/* 请在这里填写答案 */
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
  char data;
  int parent;
};
bool cmp(Evode a, Evode b) {
  return a.lowcost < b.lowcost;
}
void Kruskal(AMGraph G) {
  Evode *evodes = new Evode[(G.vexnum * (G.vexnum - 1)) / 2];
  int k = 0, cur = 0;
  for (int i = 0; i < G.vexnum; i++)
    for (int j = i + 1; j < G.vexnum; j++)
      if (G.arcs[i][j] != MaxInt) {
        evodes[k].Head = G.vexs[i];
        evodes[k].Tail = G.vexs[j];
        evodes[k].lowcost = G.arcs[i][j];
        k++;
      }
  sort(evodes, evodes + k, cmp);
  Node Vex[MVNum];
  for (int i = 0; i < G.vexnum; i++) {
    Vex[i].data = G.vexs[i];
    Vex[i].parent = i;
  }
  int count = 0;
  while (count < G.vexnum - 1) {
    int head = LocateVex(G, evodes[cur].Head);
    int tail = LocateVex(G, evodes[cur].Tail);
    if (Vex[head].parent != Vex[tail].parent) {
      printf("%c->%c\n", evodes[cur].Head, evodes[cur].Tail);
      count++;
      int oldParent = Vex[tail].parent;
      for (int i = 0; i < G.vexnum; i++)
        if (Vex[i].parent == oldParent)
          Vex[i].parent = Vex[head].parent;
    }
    cur++;
  }
}
