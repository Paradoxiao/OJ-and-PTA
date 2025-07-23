#include <cstdio>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int data[n];
  for (int &i : data)
    scanf("%d", &i);
  int min, max;
  scanf("%d %d", &min, &max);
  for (int i = 0; i < n; i++)
    if (data[i] >= min && data[i] <= max) {
      for (int j = i + 1; j < n; j++)
        data[j - 1] = data[j];
      n--;
      i--;
    }
  for (int i = 0; i < n; i++)
    printf(i ? " %d" : "%d", data[i]);
  return 0;
}