#include <iostream>
using namespace std;

#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

int *D = new int[MVNum];
bool *S = new bool[MVNum];
int *Path = new int[MVNum];

typedef struct {
  VerTexType vexs[MVNum];
  ArcType arcs[MVNum][MVNum];
  int vexnum, arcnum;
} AMGraph;

int LocateVex(AMGraph G, VerTexType v); // 该实现细节隐藏
void CreateUDN(AMGraph &G);             // 该实现细节隐藏

void ShortestPath_DIJ(AMGraph G, int v0) {
  int v, i, w, min;
  int n = G.vexnum;

  for (v = 0; v < n; ++v) {
    S[v] = false;
    D[v] = G.arcs[v0][v];
    if (D[v] < MaxInt)
      Path[v] = v0;
    else
      Path[v] = -1;
  }

  S[v0] = true;
  D[v0] = 0;

  for (i = 1; i < n; ++i) {
    min = MaxInt;
    for (w = 0; w < n; ++w)
      if (!S[w] && D[w] < min) {
        v = w;
        min = D[w];
      }
    S[v] = true;
    for (w = 0; w < n; ++w)
      if (!S[w] && G.arcs[v][w] < MaxInt && D[v] + G.arcs[v][w] < D[w]) {
        D[w] = D[v] + G.arcs[v][w];
        Path[w] = v;
      }
  }
}

void DisplayPath(AMGraph G, int begin, int temp) {
  if (Path[temp] != -1) {
    DisplayPath(G, begin, Path[temp]);
    cout << G.vexs[Path[temp]] << "->";
  }
}

int main() {
  AMGraph G;
  int i, j, num_start, num_destination;
  VerTexType start, destination;
  CreateUDN(G);
  cin >> start >> destination;
  num_start = LocateVex(G, start);
  num_destination = LocateVex(G, destination);
  ShortestPath_DIJ(G, num_start);
  DisplayPath(G, num_start, num_destination);
  cout << G.vexs[num_destination] << endl;
  return 0;
}
