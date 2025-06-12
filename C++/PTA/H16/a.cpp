#include <cstdio>
#include <iostream>
#define MVNum 10
#define MaxInt 32767
using namespace std;

struct edge {
  char adjvex;
  int lowcost;
} closedge[MVNum];

typedef struct {
  char vexs[MVNum];
  int arcs[MVNum][MVNum];
  int vexnum, arcnum;
} AMGraph;
int LocateVex(AMGraph G, char v); // 实现细节隐藏
// int Min(AMGraph G);               // 实现细节隐藏
int CreateUDN(AMGraph &G); // 实现细节隐藏

void Prim(AMGraph G, char u);

int main() {
  AMGraph G;
  CreateUDN(G);
  char u;
  cin >> u;
  Prim(G, u);
  return 0;
}

/* 请在这里填写答案 */
struct point {
  char c;
  int weight;
  bool intree;
};
void Prim(AMGraph G, char u) {
  point p[G.vexnum];
  for (int i = 0; i < G.vexnum; i++) {
    p[i].c = G.vexs[i];
    p[i].weight = MaxInt;
    p[i].intree = false;
  }
  for (int i = 0; i < G.vexnum - 1; i++) {
    int uIndex = LocateVex(G, u);
    p[uIndex].weight = 0;
    p[uIndex].intree = true;
    for (int j = 0; j < G.vexnum; j++)
      if (G.arcs[uIndex][j] != MaxInt && !p[j].intree)
        if (G.arcs[uIndex][j] < p[j].weight) {
          p[j].weight = G.arcs[uIndex][j];
          p[j].c = G.vexs[j];
        }
    int minWeight = MaxInt;
    int minIndex = -1;
    for (int j = 0; j < G.vexnum; j++)
      if (!p[j].intree && p[j].weight < minWeight) {
        minWeight = p[j].weight;
        minIndex = j;
      }
    u = p[minIndex].c;
    cout << p[uIndex].c << "->" << p[minIndex].c << endl;
    p[minIndex].intree = true;
  }
}
