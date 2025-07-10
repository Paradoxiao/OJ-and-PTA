#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account {
private:
  string username;
  string password;

protected:
public:
  Account(const string &name = "", const string &pass = "") : username(name), password(pass) {}
  void setUser(const string &name, const string &pass) {
    username = name, password = pass;
  }
  void setUsername(const string &name) {
    username = name;
  }
  void setPassword(const string &pass) {
    password = pass;
  }
  string getUsername() const {
    return username;
  }
  string getPassword() const {
    return password;
  }
};
struct Accounts {
private:
  vector<Account> accounts;

protected:
public:
  void addUser(const string &username, const string &password) {
    accounts.push_back(Account(username, password));
  }
  void login(const string &username, const string &password) {
    for (vector<Account>::iterator it = accounts.begin(); it != accounts.end(); ++it)
      if (it->getUsername() == username) {
        if (it->getPassword() == password)
          cout << "welcome" << endl;
        else
          cout << "password error" << endl;
        return;
      }
    cout << "user name error" << endl;
  }
};
int main() {
  int n, i;
  string a, b;
  Accounts accounts;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    accounts.addUser(a, b);
  }
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    accounts.login(a, b);
  }
  return 0;
}

/*

Description

定义类Accounts，记录若干个用户的用户名和密码，假定所有用户名不重复。判断用户输入的用户名和密码能否登录。

如果用户名不存在，则输出：user name error

如果用户名正确，但是密码错误，则输出：password error

如果用户名、密码均正确，则输出：welcome

Accounts类的addUser方法用于增加新用户，两个参数依次是用户名和密码；login方法用于尝试登录系统，两个参数依次是用户名和密码。
Input

输入分两部分。

第一部分第一行输入一个正整数N，表示后面有N行输入，每行包括两个字符串，分别是用户名和密码，均不含空白符。用于建立账户信息。

第二部分第一行输入一个正整数M，表示后面有M行输入，每行包括两个字符串，分别是用户名和密码，均不含空白符。用于测试能否登录。
Output

输出有M行，与第二部分输入的M行一一对应，输出结果为：

如果用户名不存在，则输出：user name error

如果用户名正确，但是密码错误，则输出：password error

如果用户名、密码均正确，则输出：welcome

Sample Input
4
tom tom
jack tom
mary jack
richar 123
3
tom jack
jack tom
richard 123
Sample Output
password error
welcome
user name error
HINT

Append Code
append.cc,
[Submit][Status]

*/
