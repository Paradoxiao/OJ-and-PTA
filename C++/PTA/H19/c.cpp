#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *a = new int[n], *b = new int[n], *c = new int[2 * n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  int i = 0, j = 0, k = 0;
  while (i < n && j < n)
    if (a[i] > b[j])
      c[k++] = b[j++];
    else
      c[k++] = a[i++];
  while (j < n)
    c[k++] = b[j++];
  while (i < n)
    c[k++] = a[i++];
  cout << c[(2 * n - 1) / 2] << endl;
  return 0;
}
/*

7-1【求并集时不去重，用尽量高效的算法】 两个有序序列的中位数
7-1【求并集时不去重，用尽量高效的算法】 两个有序序列的中位数
分数 25
作者 DS课程组
单位 浙江大学

已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列A0​,A1​,⋯,AN−1​的中位数指A(N−1)/2​的值,即第⌊(N+1)/2⌋个数（A0​为第1个数）。
输入格式:

输入分三行。第一行给出序列的公共长度N（0<N≤100000），随后每行输入一个序列的信息，即N个非降序排列的整数。数字用空格间隔。
输出格式:

在一行中输出两个输入序列的并集序列的中位数。
输入样例1:
Sample Input:
5
1 3 5 7 9
2 3 4 5 6

输出样例1:
Sample Output:
4
HINT
输入样例2:

6
-100 -10 1 1 1 1
-50 0 2 3 4 5

输出样例2:

1

代码长度限制
16 KB
时间限制
200 ms
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
0/7
单选题
0/9
函数题
2/2
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
