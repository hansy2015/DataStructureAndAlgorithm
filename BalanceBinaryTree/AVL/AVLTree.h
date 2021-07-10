#include <iostream>

using namespace std;

template<class K, class V>
class AVLTree {
private:
  struct Node {
    K key;
    V value;
    Node* left;
    Node* right;
    int height;

    Node(K key, V value) {
      this->key = key;
      this->value = value;
      this->left = nullptr;
      this->right = nullptr;
      this->height = 1;
    }
  };

  Node* root;
  int size;
public:
  AVLTree() {
    this->root = nullptr;
    this->size = 0;
  }
public:
  int getSize() { return size; }
  bool isEmpty() { return size == 0; }
  void add(K key, V value) { root = add(root, key, value); }

  bool isBST() {
    vector<K> keys;
    inOrder(root, keys);
    for (int i = 1; i < (int)keys.size(); i++) {
      if (keys[i - 1] > keys[i]) {
        return false;
      }
    }
    return true;
  }

  bool isBalanced() {
    return isBalanced(root);
  }

  

private:
  bool isBalanced(Node* node) {
    if (node == nullptr) {
      return true;
    }
    int balanceFactor = getBalanceFactor(node);
    if ((int)abs(balanceFactor) > 1) {
      return false;
    }
    return isBalanced(node->left) && isBalanced(node->right);
  }
  void inOrder(Node* node, vector<K>& keys) {
    if (node == nullptr) {
      return;
    }
    inOrder(node->left, keys);
    keys.push_back(node->key);
    inOrder(node->right, keys);
  }
  int getHeight(Node* node) {
    if (node == nullptr) {
      return 0;
    } 
    return node->height;
  }

  int getBalanceFactor(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
  }


  Node* add(Node* node, K key, V value) {
    if (node == nullptr) {
      size++;
      return new Node(key, value);
    }
    if (key < node->key) {
      node->left = add(node->left, key, value);
    } else if (key > node->key) {
      node->right = add(node->right, key, value);
    } else {
      node->value = value;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);
    return node;
  }

};