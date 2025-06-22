#include <iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

int Path[MVNum][MVNum];
int D[MVNum][MVNum];

typedef struct {
  VerTexType vexs[MVNum];
  ArcType arcs[MVNum][MVNum];
  int vexnum, arcnum;
} AMGraph;

int LocateVex(AMGraph G, VerTexType v); // 实现细节隐藏
void CreateUDN(AMGraph &G);             // 实现细节隐藏

void ShortestPath_Floyed(AMGraph G) {
  int i, j, k;
  for (i = 0; i < G.vexnum; ++i)
    for (j = 0; j < G.vexnum; ++j) {
      D[i][j] = G.arcs[i][j];
      if (D[i][j] < MaxInt && i != j)
        Path[i][j] = i;
      else
        Path[i][j] = -1;
    }
  for (k = 0; k < G.vexnum; ++k)
    for (i = 0; i < G.vexnum; ++i)
      for (j = 0; j < G.vexnum; ++j)
        if (D[i][k] < MaxInt && D[k][j] < MaxInt && D[i][k] + D[k][j] < D[i][j]) {
          D[i][j] = D[i][k] + D[k][j];
          Path[i][j] = Path[k][j];
        }
}

void DisplayPath(AMGraph G, int begin, int temp) {
  if (Path[begin][temp] != -1) {
    DisplayPath(G, begin, Path[begin][temp]);
    cout << G.vexs[Path[begin][temp]] << "->";
  }
}

int main() {
  AMGraph G;
  char start, destination;
  int num_start, num_destination;
  CreateUDN(G);
  ShortestPath_Floyed(G);
  cin >> start >> destination;
  num_start = LocateVex(G, start);
  num_destination = LocateVex(G, destination);
  DisplayPath(G, num_start, num_destination);
  cout << G.vexs[num_destination] << endl;
  cout << D[num_start][num_destination];
  return 0;
}
