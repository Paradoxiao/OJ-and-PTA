#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  string src = "", temp;
  while (true) {
    getline(cin, temp);
    if (temp == ".")
      break;
    src += temp;
  }
  stack<string> ops;
  for (int i = 0; i < src.size(); i++) {
    if (src[i] == '(' || src[i] == '[' || src[i] == '{')
      ops.push(string(1, src[i]));
    if (src[i] == ')') {
      if (ops.empty()) {
        cout << "NO\n?-)";
        return 0;
      } else if (ops.top() != "(") {
        printf("NO\n%s-?", ops.top().c_str());
        return 0;
      } else
        ops.pop();
    }
    if (src[i] == ']') {
      if (ops.empty()) {
        cout << "NO\n?-]";
        return 0;
      } else if (ops.top() != "[") {
        printf("NO\n%s-?", ops.top().c_str());
        return 0;
      } else
        ops.pop();
    }
    if (src[i] == '}') {
      if (ops.empty()) {
        cout << "NO\n?-}";
        return 0;
      } else if (ops.top() != "{") {
        printf("NO\n%s-?", ops.top().c_str());
        return 0;
      } else
        ops.pop();
    }
    if (src[i] == '/' && src[i + 1] == '*') {
      ops.push("/*");
      i++;
    } else if (src[i] == '*' && src[i + 1] == '/') {
      if (ops.empty()) {
        cout << "NO\n?-*/";
        return 0;
      } else if (ops.top() != "/*") {
        printf("NO\n%s-?", ops.top().c_str());
        return 0;
      } else {
        ops.pop();
        i++;
      }
    }
  }
  if (ops.empty())
    cout << "YES";
  else
    printf("NO\n%s-?", ops.top().c_str());
  return 0;
}