#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct Node {
  int v, w;
};
int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<list<Node>> graph(n);
  vector<int> city(n);
  for (int &i : city)
    cin >> i;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w}), graph[v].push_back({u, w});
  }
  vector<int> dist(n, 1073741824), prev(n, -1), pathcnt(n, 0), maxcity(n, 0);
  vector<bool> visited(n, 0);
  priority_queue<int, vector<int>, function<bool(int, int)>> q([&dist](int a, int b) { return dist[a] > dist[b]; });
  q.push(s);
  dist[s] = 0;
  pathcnt[s] = 1;
  maxcity[s] = city[s];
  while (!q.empty()) {
    auto u = q.top();
    q.pop();
    if (visited[u])
      continue;
    visited[u] = 1;
    for (auto &[v, w] : graph[u])
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        maxcity[v] = maxcity[u] + city[v];
        pathcnt[v] = pathcnt[u];
        q.push(v);
      } else if (dist[v] == dist[u] + w) {
        pathcnt[v] += pathcnt[u];
        if (maxcity[u] + city[v] > maxcity[v]) {
          maxcity[v] = maxcity[u] + city[v];
          prev[v] = u;
        }
      }
  }
  cout << pathcnt[d] << " " << maxcity[d] << endl;
  stack<int> path;
  for (int p = d; p != -1; p = prev[p])
    path.push(p);
  bool not_first = 0;
  while (!path.empty()) {
    cout << (not_first ? " " : "") << path.top();
    path.pop();
    not_first = 1;
  }
}
/*

7-1 城市间紧急救援
分数 25
作者 陈越
单位 浙江大学

作为一个城市的应急救援队伍的负责人，你有一张特殊的全国地图。在地图上显示有多个分散的城市和一些连接城市的快速道路。每个城市的救援队数量和每一条连接两个城市的快速道路长度都标在地图上。当其他城市有紧急求助电话给你的时候，你的任务是带领你的救援队尽快赶往事发地，同时，一路上召集尽可能多的救援队。
输入格式:

输入第一行给出 4 个正整数 n、m、s、d，其中 n（2≤n≤500）是城市的个数，顺便假设城市的编号为 0 ~ (n−1)；m 是快速道路的条数；s 是出发地的城市编号；d是目的地的城市编号。

第二行给出 n 个正整数，其中第 i 个数是第 i 个城市的救援队的数目，数字间以空格分隔。随后的 m 行中，每行给出一条快速道路的信息，分别是：城市 1、城市 2、快速道路的长度，中间用空格分开，数字均为整数且不超过 500。输入保证救援可行且最优解唯一。
输出格式:

第一行输出最短路径的条数和能够召集的最多的救援队数量。第二行输出从 s 到 d 的路径中经过的城市编号。数字间以空格分隔，输出结尾不能有多余空格。
输入样例:
Sample Input:
4 5 0 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2

输出样例:
Sample Output:
2 60
0 1 3
HINT

代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
栈限制
8192 KB
C++ (g++)
1

无提交记录
题目总览
作答 / 题数
判断题
0/4
单选题
0/10
程序填空题
0/2
函数题
1/1
编程题
0/1
编程题
1
当前1 - 1项，共1项
概览
题目列表
提交列表
排名
答题中
2 天
Avatar
paradoxiao
*/
