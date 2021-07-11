#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<class T>
class MaxHeap {
private:
  vector<T> data;
public:
  
  MaxHeap() {}
  MaxHeap(vector<T> arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
      data.push_back(arr[i]);
    }
    for (int i = parent((int)data.size() - 1); i >= 0; i--) {
      shiftDown(i);
    }
  }

  int size() {
    return (int)data.size();
  }

  bool isEmpty() {
    return size() == 0;
  }

  void add(T item) {
    data.push_back(item);
    shiftUp((int)data.size() - 1);
  }
  T getMax() {
    assert(!isEmpty());
    swap(data[0], data.back());
    T ret = data.back();
    data.pop_back();
    shiftDown(0);
    return ret;
  }

private:
  int parent(int index) {
    // if (index == 0) {
    //   throw "index == 0";
    // }
    assert(index > 0);
    return (index - 1) / 2;
  }

  int leftChild(int index) {
    return index * 2 + 1;
  }

  int rightChild(int index) {
    return index * 2 + 2;
  }

  void shiftUp(int K) {
    T Comp = data[K];
    while (K > 0 && data[parent(K)] < Comp) {
      data[K] = data[parent(K)];
      K = parent(K);
    }
    data[K] = Comp;
  }

  void shiftDown(int K) {
    T Comp = data[K];
    while (leftChild(K) < size()) {
      int j = leftChild(K);
      if (j + 1 < size() && data[j] < data[j + 1]) {
        j += 1;
      }
      if (Comp > data[j]) {
        break;
      }
      data[K] = data[j];
      K = j;
    }
    data[K] = Comp;
  }
  

  void replace(T e) {
    assert(!isEmpty());
    data[0] = e;
  }

};