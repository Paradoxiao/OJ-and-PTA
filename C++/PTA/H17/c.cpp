#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
  int from, to, weight, time;
};
struct Node {
  vector<Edge> outedges;
  vector<Edge> inedges;
};

int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  vector<Node> nodes(n + 1);
  vector<int> indegree(n + 1, 0);
  vector<int> outdegree(n + 1, 0);
  vector<int> early_time(n + 1, 0);
  vector<Edge> edges(m + 1);
  for (int i = 1; i <= m; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edges[i] = {from, to, weight, i};
    nodes[from].outedges.push_back({from, to, weight});
    nodes[to].inedges.push_back({from, to, weight});
    indegree[to]++;
    outdegree[from]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (indegree[i] == 0)
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), cnt++;
    for (const auto &edge : nodes[u].outedges) {
      int v = edge.to;
      early_time[v] = max(early_time[v], early_time[u] + edge.weight);
      indegree[v]--;
      if (indegree[v] == 0)
        q.push(v);
    }
  }
  if (cnt < n) {
    cout << 0 << endl;
    return 0;
  }
  int total_time = *max_element(early_time.begin(), early_time.end());
  cout << total_time << endl;
  vector<int> late_time(n + 1, total_time);
  queue<int> rq;
  for (int i = 1; i <= n; i++)
    if (outdegree[i] == 0)
      rq.push(i);
  while (!rq.empty()) {
    int u = rq.front();
    rq.pop();
    for (const auto &edge : nodes[u].inedges) {
      int v = edge.from;
      late_time[v] = min(late_time[v], late_time[u] - edge.weight);
      outdegree[v]--;
      if (outdegree[v] == 0)
        rq.push(v);
    }
  }
  sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) -> bool {
    if (a.from != b.from)
      return a.from < b.from;
    return a.time > b.time;
  });
  for (const auto &edge : edges)
    if (early_time[edge.from] + edge.weight == late_time[edge.to])
      cout << edge.from << "->" << edge.to << endl;
  return 0;
}

/*
Sample Input
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
4 6 6
5 7 5
6 7 2
Sample Output
17
1->2
2->4
4->6
6->7
HINT
*/
