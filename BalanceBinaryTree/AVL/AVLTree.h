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
  /*
              y                                                          x
            /  \                                                        / \
          x     T4                                                     z    y
        /  \             -------------------->                        / \   / \
      z    T3                                                        T1  T2 T3 T4
    /  \
  T1   T2
  */
  Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T3 = x->right;
    // 向右旋转
    x->right = y;
    y->left = T3;
    // 更新height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
  }
  /*
                y                                                               x
              /  \                                                            /   \
            T4    x                                                          y     z
                /   \    ------------------->                              /  \   / \
              T3     z                                                    T4  T3 T1  T2 
                    / \
                  T1  T2  
  */
  Node* leftRotate(Node* y) {
    Node* x = y->right;
    Node* T3 = x->left;
    // 向左旋转
    x->left = y;
    y->right = T3;
    // 更新height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
  }
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
    // 更新高度值
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    // 计算平衡因子
    int balanceFactor = getBalanceFactor(node);
    // 平衡维护
    // 左边的左边失去了平衡
    
    if (balanceFactor > 1 && getBalanceFactor(nod->left) >= 0) {
      return rightRotate(node);
    }
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
      return leftRotate(node);
    }
    
    return node;
  }

};