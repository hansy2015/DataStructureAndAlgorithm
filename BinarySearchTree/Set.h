#include <iostream>

using namespace std;

class Set {
public:
  Set() {}
  virtual void add(string e) = 0;
  virtual void remove(string e) = 0;
  virtual bool contains(string e) = 0;
  virtual int getSize() = 0;
  virtual bool isEmpty() = 0;
};
