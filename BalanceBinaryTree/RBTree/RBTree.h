/*
  每一个节点要么红色要么是黑色
  根节点一定是黑色的
  每一个叶子节点（最后的空节点）是黑色的
  红节点的孩子节点一定是黑节点
  从一个节点出发到任意叶子节点经过的黑节点的数量是一样的

  红黑树是黑平衡的，严格意义上，红黑树不是平衡二叉树，最大高度2logn O(logn)
*/


#include <iostream>

using namespace std;

const bool RED = true;
const bool BLACK = false;

template<class K, class V>
class RBTree {
private:
  struct Node {
    K key;
    V val;
    Node* left;
    Node* right;
    bool color;

    Node(K key, V val) {
      this->key = key;
      this->val = val;
      left = nullptr;
      right = nullptr;
      color = RED;
    }
  };

  Node* root;
  int size;
public:
  RBTree() {
    root = nullptr;
    size = 0;
  }

  int getSize() {return size;}
  bool isEmpty() {return size == 0;}
  bool isRed(Node* node) {
    if (node == nullptr) {
      return BLACK;
    }
    return node->color;
  }
  // 向红黑树中添加新的元素
  void add(K key, V val) {
    root = add(root, key, val);
    root->color = BLACK;
  }
private:
  /*
              node                                              x   
            /      \                                         /      \
           T1       x        ----------->                  node     T3
                  /   \                                   /   \
                T2    T3                                 T1   T2
  */
  Node* leftRotate(Node* node) {
    Node* x = node->right;
    // 左旋转
    node->right = x->left;
    x->left = node;
    // 维护颜色
    x->color = node->color;
    node->color = RED;
    return node;
  }
  /*
                  node                                    x
                /      \                               /     \
               x       T2    -------->                y      node
            /     \                                         /     \
          y       T1                                       T1     T2



  */
  Node* rightNode(Node* node) {
    Node* x = node->left;
    node->left = x->right;
    x->right = node;

    // 颜色维护

    x->color = node->color;
    node->color = RED;

    return x;
  }
  // 颜色反转
  void filpColor(Node* node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
  }
  /*

          B                   B                         B                            B                                R
        /   ------>         /       ------>            /        ------>            /   \           ------>          /   \ 
      R                    R                          R                           R     R                          B     B
                            \                        /
                             R                      R
  */
  void add(Node* node, K key, V value) {
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
    if (isRed(node->right) && !isRed(node->left)) {
      node = leftRotate(node);
    }
    if (isRed(node->left) && isRed(node->left->left)) {
      node = rightRotate(node);
    }
    if (isRed(node->left) && isRed(node->right)) {
      filpColor(node);
    }
    return node;
  }
};