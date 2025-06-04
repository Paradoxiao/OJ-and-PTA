#include <iostream>
using namespace std;
class MyList {
private:
  int *data;
  int size;
  int capacity;

  void expand() {
    int newCapacity = capacity * 2;
    int *newData = new int[newCapacity];
    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }

public:
  MyList(int len) {
    size = 0;
    capacity = len;
    data = new int[capacity];
  }
  ~MyList() {
    delete[] data;
  }
  void append(int value) {
    if (size >= capacity)
      expand();
    data[size++] = value;
  }
  void insert(int pos, int value) {
    if (pos >= 0 && pos <= size) {
      if (size >= capacity)
        expand();
      for (int i = size; i > pos; i--)
        data[i] = data[i - 1];
      data[pos] = value;
      size++;
    }
  }
  void erase(int pos) {
    if (pos >= 0 && pos < size) {
      for (int i = pos; i < size - 1; i++)
        data[i] = data[i + 1];
      size--;
    }
  }
  void set(int pos, int value) {
    if (pos >= 0 && pos < size)
      data[pos] = value;
  }
  void show() {
    for (int i = 0; i < size; i++) {
      if (i)
        cout << " ";
      cout << data[i];
    }
    cout << endl;
  }
};
int main() {
  int cases, len, data, pos;
  char op;
  cin >> len;
  MyList myList(len);
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> op;
    switch (op) {
    case 'A':
      cin >> data;
      myList.append(data);
      break;
    case 'I':
      cin >> pos >> data;
      myList.insert(pos, data);
      break;
    case 'E':
      cin >> pos;
      myList.erase(pos);
      break;
    case 'S':
      cin >> pos >> data;
      myList.set(pos, data);
    }
    myList.show();
  }
  return 0;
}