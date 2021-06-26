#include <iostream>
#include <vector>
#include <ctime>
#include <queue>

using namespace std;

template<class E>
class BST {
private:
  struct Node {
    E e;
    Node* left;
    Node* right;

    Node(E e) {
      this->e = e;
      this->left = nullptr;
      this->right = nullptr;
    }
  };

  Node* root;
  int size;

public:
  BST() {
    root = nullptr;
    size = 0;
  }

  int Size() { return size; }

  bool isEmpty() { return size == 0; }

  void add(E e) { root = add(root, e); }

  bool contains(E e) { return contains(root, e); }

  void preOrder() { preOrder(root); }

  void inOrder() { inOrder(root); }

  void postOrder() { postOrder(root); }

  void levelOrder() {
    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
      Node* cur = que.front();
      que.pop();
      cout << cur->e << endl;
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    }
  }

  E minimum() {
    if (size == 0) {
      throw "BST is empty";
    }
    return minimum(root)->e;
  }

  E maximum() {
    if (size == 0) {
      throw "BST is empty";
    }
    return maximum(root)->e;
  }
  // 从二分搜索树中删除最小值所在节点
  E removeMin() {
    E ret = minimum();
    root = removeMin(root);
    return ret;
  }

  E removeMax() {
    E ret = maximum();
    root = removeMax(root);
    return ret;
  }

  void remove(E e) {
    remove(root, e);
  }


private:
  Node* add(Node* node, E e) {
    if (node == nullptr) {
      ++size;
      return new Node(e);
    }
    if (node->e > e) {
      node->left = add(node->left, e);
    } else if (node->e < e) {
      node->right = add(node->right, e);
    }
    return node;
  }

  bool contains(Node* node, E e) {
    if (node == nullptr) {
      return false;
    }
    if (node->e == e) {
      return true;
    }
    if (node->e < e) {
      return contains(node->left, e);
    } else {
      return contains(node->right, e);
    }
  }

  void preOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    cout << node->e << endl;
    preOrder(node->left);
    preOrder(node->right);
  }

  void preOrderNR() {
    vector<Node*> stak;
    stak.push_back(root);
    while (!stak.empty()) {
      Node* cur = stak.back();
      stak.pop_back();
      if (cur->right) stak.push_back(cur->right);
      if (cur->left) stak.push_back(cur->left);
    }
  }

  void inOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    inOrder(node->left);
    cout << node->e << endl;
    inOrder(node->right);
  }

  void postOrder(Node* node) {
    if (node == nullptr) {
      return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->e << endl;
  }

  Node* minimum(Node* node) {
    if (node->left == nullptr) {
      return node;
    }
    return minimum(node->left);
  }

  Node* maximum(Node* node) {
    if (node->right == nullptr) {
      return node;
    }
    return maximum(node->right);
  }

  Node* removeMin(Node* node) {
    if (node->left == nullptr) {
      Node* rightNode = node->right;
      node->right = nullptr;
      --size;
      return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
  }

  Node* removeMax(Node* node) {
    if (node->right == nullptr) {
      Node* leftNode = node->left;
      node->left = nullptr;
      --size;
      return leftNode;
    }
    node->right = removeMax(node->right);
    return node;
  }

  Node* remove(Node* node, E e) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->e > e) {
      node->left = remove(node->left, e);
    } else if (node->e < e) {
      node->right = remove(node->right, e);
    } else {
      if (node->left == nullptr) {
        Node* rightNode = node->right;
        node->right = nullptr;
        size--;
        return rightNode;
      }
      if (node->right == nullptr) {
        Node* leftNode = node->left;
        node->left = nullptr;
        size--;
        return leftNode;
      }

      Node* success = new Node(minimum(node->right)->e);
      success->right = removeMin(node->right);
      success->left = node->left;
      node->left = node->right = nullptr;
      return success;
    }
    return node;
  }

};
/*
int main() {
  BST<int> bst;
  srand(time(0));
  int n = 1000;
  for (int i = 0; i < n; i++) {
    bst.add(rand() % n + 1);
  }
  vector<int> nums;
  while (!bst.isEmpty()) {
    nums.push_back(bst.removeMin());
  }
  for (int i = 0; i < (int)nums.size(); i++) {
    cout << nums[i] << endl;
  }
  for (int i = 1; i < (int)nums.size(); i++) {
    if (nums[i] < nums[i - 1]) {
      throw "fuck";
    }
  }
  cout << "yes" << endl;
  return 0;
}*/