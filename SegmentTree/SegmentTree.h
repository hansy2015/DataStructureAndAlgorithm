#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
  vector<int> data;
  vector<int> tree;
  function<int(int, int)> Merge;
public:
  SegmentTree(vector<int> arr, function<int(int, int)> Merge) {
    for (int t : arr) {
      data.push_back(t);
    }
    tree.resize((int)arr.size() * 4);
    this->Merge = Merge;
    build(0, 0, size() - 1);
  }

  int size() {
    return (int)data.size();
  }
  

  int get(int index) {
    assert(index >= 0 && index < size());
    return data[index];
  }

  int query(int queryL, int queryR) {
    return query(0, 0, size() - 1, queryL, queryR);
  }

  void Set(int index, int e) {
    data[index] = e;
    modify(0, 0, size() - 1, index, e);
  }

private:
  int leftChild(int index) {
    return index * 2 + 1;
  }

  int rightChild(int index) {
    return index * 2 + 2;
  }

  void build(int treeIndex, int l, int r) {
    if (l == r) {
      tree[treeIndex] = data[l];
      return;
    }
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);

    int mid = l + (r - l) / 2;
    build(leftTreeIndex, l, mid);
    build(rightTreeIndex, mid + 1, r);
    tree[treeIndex] = this->Merge(tree[leftTreeIndex], tree[rightTreeIndex]);
  }

  int query(int treeIndex, int l, int r, int queryL, int queryR) {
    if (l == queryL && r == queryR) {
      return tree[treeIndex];
    }
    int mid = l + (r - l) / 2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);
    if (queryL >= mid + 1) {
      return query(rightTreeIndex, mid + 1, r, queryL, queryR);
    } else if (queryR <= mid) {
      return query(leftTreeIndex, l, mid, queryL, queryR);
    } else {
      int leftRet = query(leftTreeIndex, l, mid, queryL, mid);
      int rightRet = query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
      return this->Merge(leftRet, rightRet);      
    }
  }

  void modify(int treeIndex, int l, int r, int index, int e) {
    if (l == r) {
      tree[treeIndex] = e;
      return;
    }
    int mid = (l + r) / 2;
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);
    if (index >= mid + 1) {
      modify(rightTreeIndex, mid + 1, r, index, e);
    } else {
      modify(leftTreeIndex, l, mid, index, e);
    }
    tree[treeIndex] = Merge(tree[leftTreeIndex], tree[rightTreeIndex]);
  }

};