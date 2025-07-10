#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Song {
private:
  static int cnt;

protected:
  string name;

public:
  Song(string s) : name(s) {
    cnt++;
  }
  Song() {}
  string getName() const {
    return name;
  }
  virtual ~Song() {}
  virtual string getType() const = 0;
  static int getCntOfSongs() {
    return cnt;
  }
};
class Pop : public Song {
private:
  static int cntOfPops;

protected:
public:
  Pop(string s) : Song(s) {
    cntOfPops++;
  }
  string getType() const {
    return "popular";
  }
  static int getCntOfPops() {
    return cntOfPops;
  }
};
class Folk : public Song {
private:
  static int cntOfFolks;

protected:
public:
  Folk(string s) : Song(s) {
    cntOfFolks++;
  }
  string getType() const {
    return "folk";
  }
  static int getCntOfFolks() {
    return cntOfFolks;
  }
};
class Bel : public Song {
private:
  static int cntOfBels;

protected:
public:
  Bel(string s) : Song(s) {
    cntOfBels++;
  }
  string getType() const {
    return "Bel Canto";
  }
  static int getCntOfBels() {
    return cntOfBels;
  }
};
class Singer {
private:
  static int cnt;

protected:
public:
  string name;
  vector<Song *> songs;

  Singer(string s) : name(s) {
    cnt++;
  }
  Singer() {}
  void addASong(string s, int t) {
    Song *song = NULL;
    switch (t) {
    case 1:
      song = new Pop(s);
      break;
    case 2:
      song = new Folk(s);
      break;
    case 3:
      song = new Bel(s);
      break;
    default:
      return;
    }
    songs.push_back(song);
  }
  void singASong(string s) {
    for (vector<Song *>::iterator it = songs.begin(); it != songs.end(); ++it)
      if ((*it)->getName() == s) {
        cout << name << " sings " << s << " in " << (*it)->getType() << " style." << endl;
        return;
      }
    cout << name << " doesn't sing " << s << "." << endl;
  }
  static int getCntOfSingers() {
    return cnt;
  }
};
class SingerList {
private:
  vector<Singer> singers;

protected:
public:
  friend istream &operator>>(istream &is, SingerList &lst) {
    int n;
    is >> n;
    lst.singers.resize(n);
    for (int i = 0; i < n; ++i) {
      string name;
      int m;
      is >> name >> m;
      lst.singers[i] = Singer(name);
      for (int j = 0; j < m; ++j) {
        int t;
        string songName;
        is >> t >> songName;
        lst.singers[i].addASong(songName, t);
      }
    }
    return is;
  }
  friend ostream &operator<<(ostream &os, const SingerList &lst) {
    for (vector<Singer>::const_iterator it = lst.singers.begin(); it != lst.singers.end(); ++it) {
      os << it->name << " : ";
      for (vector<Song *>::const_iterator songIt = it->songs.begin(); songIt != it->songs.end(); ++songIt)
        os << (songIt == it->songs.begin() ? "" : " ") << (*songIt)->getName();
      os << endl;
    }
    return os;
  }
  void Choose(const string &s1, const string &s2) {
    for (vector<Singer>::iterator it = singers.begin(); it != singers.end(); ++it)
      if (it->name == s1) {
        for (vector<Song *>::iterator songIt = it->songs.begin(); songIt != it->songs.end(); ++songIt)
          if ((*songIt)->getName() == s2) {
            cout << s1 << " sings " << s2 << " in " << (*songIt)->getType() << " style." << endl;
            return;
          }
        cout << s1 << " doesn't sing " << s2 << "." << endl;
        return;
      }
    cout << "Singer " << s1 << " doesn't exist." << endl;
  }
};
int Song::cnt = 0;
int Pop::cntOfPops = 0;
int Folk::cntOfFolks = 0;
int Bel::cntOfBels = 0;
int Singer::cnt = 0;
int main() {
  cout << "In beginning, there are ";
  cout << Singer::getCntOfSingers() << " singers, and ";
  cout << Song::getCntOfSongs() << " songs." << endl;
  Singer liuh("LiuHuan");
  liuh.addASong("XiongDi", 1);
  liuh.addASong("SanGuo", 2);
  liuh.addASong("SongBie", 3);
  liuh.singASong("XiongDi");
  liuh.singASong("SanGuo");
  liuh.singASong("SongBie");
  liuh.singASong("MeiYou");

  SingerList lst;
  string s1, s2;
  cin >> lst;
  cout << lst;
  cout << "Now, there are ";
  cout << Singer::getCntOfSingers() << " singers, and ";
  cout << Song::getCntOfSongs() << " songs. Including ";
  cout << Pop::getCntOfPops() << " pop songs, ";
  cout << Folk::getCntOfFolks() << " folk songs, and ";
  cout << Bel::getCntOfBels() << " Bel Canto songs." << endl;
  while (cin >> s1 >> s2) {
    lst.Choose(s1, s2);
  }
  return 0;
}

/*

Description
Yang要下海创业，开一家量贩式KTV。现在需要你来帮他编写一个C++程序来实现点歌的功能。至少需要定义如下类及其成员：
1. Song类：歌曲类，具有：
（1）歌曲名属性：一个不含空白符的字符串。
（2）static int getCntOfSongs()：获得创建的歌曲的总数。
2. Pop类：是Song类的子类，具有static int getCntOfPops()方法，返回该类型的歌曲的总数。
3. Folk类：是Song类的子类，具有static int getCntOfFolks()方法，返回该类型的歌曲的总数。
4. Bel类：是Song类的子类，具有static int getCntOfBels()方法，返回该类型的歌曲的总数。
5. Singer类：歌手类，具有：
（1）歌手名属性：一个不含空白符的字符串。
（2）所演唱的歌曲列表。
（3）void addASong(string s, int t)：添加一首该歌手演唱的歌曲，其中s为歌曲名，t为歌曲类型（1、2、3分别表示Pop、Folk和Bel类的歌曲）。
（4）void singASong(string)：根据指定的歌曲名，演唱这首歌。分为两种情况：如果歌手所演唱的歌曲列表中有参数指定的歌曲名，则输出：
$ sings % in # style.
其中：$是歌手名字，%是歌曲名字，#是歌曲类型（为：popular、folk或Bel Canto之一）。
如果指定歌曲名不存在，则输出：
$ doesn’t sing %.
$、%含义同前。
（5）static int getCntOfSingers()：获得创建的歌手的人数。
6.SingerList类：点歌单类，具有：
（1）歌手列表。
（2）重载的输入输出运算符。其中重载的输入运算符按照如下格式输入数据：
第1行N>0，表示有N名歌手。之后有N行。
之后的N行，每行是一个歌手及其演唱的歌曲，是一系列用空格分开的数据。每行的第一个字符串（不含空白符）是歌手的名字。第2个是整数M>0，表示该歌手演唱了M首歌曲。M后面有M组输入，每组输入包括1个整数K和1个不含空白符的字符串S，其中K=1、2或者3，分别对应于pop、folk和Bel
Canto三种歌曲类型，S是歌曲名。 重载的输出运算符按照如下格式输出歌手及歌曲列表： 每个歌手及其演唱的歌曲占一行，每行的格式为： $ : %1 %2 … 其中$为歌手名，%1、%2等为该歌手演唱的歌曲名列表，两两之间用1个空格隔开。 （3）void Choose(string s1, string
s2)方法：根据参数指定的歌手名s1、歌曲名s2输出。分三种情况： 如果s1指定的歌手不存在，则输出： Singer $ doesn't exist. 如果s1存在，但是该歌手没有演唱s2指定的歌曲，则输出： $ doesn’t sing %. 如果s1、s2能够确定某首歌曲，则输出： $ sings % in # style.
上述$、#和%的含义同前。

Input
输入分为2部分。
第1部分是按照SingerList类的要求输入的歌手及歌曲信息。
第2部分也有多行，每行包括2个字符串，分别是指定的歌手名和歌曲名。
假定所有的歌手名、歌曲名均不相同。

Output

见样例。

Sample Input
3
Tom 4 1 ChangJiu 2 DuanZan 3 Main 1 Object
Jack 1 1 Output
Mary 2 1 Input 3 GCC
Tom DuanZan
Jack Input
Mary GCC
CUI BIGDATA
Sample Output
In beginning, there are 0 singers, and 0 songs.
LiuHuan sings XiongDi in popular style.
LiuHuan sings SanGuo in folk style.
LiuHuan sings SongBie in Bel Canto style.
LiuHuan doesn't sing MeiYou.
Tom : ChangJiu DuanZan Main Object
Jack : Output
Mary : Input GCC
Now, there are 4 singers, and 10 songs. Including 5 pop songs, 2 folk songs, and 3 Bel Canto songs.
Tom sings DuanZan in folk style.
Jack doesn't sing Input.
Mary sings GCC in Bel Canto style.
Singer CUI doesn't exist.
HINT

Append Code
append.cc,
[Submit][Status]

*/
