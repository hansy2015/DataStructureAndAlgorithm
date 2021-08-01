#include <iostream>
#include <list>

using namespace std;

template<class K, class V>
class LRUCache {
private:
  struct Node {
    K key;
    V val;
    Node() {}
    Node(K _key, V _val) : key(_key), val(_val) {}
  };

private:
  list<Node> l;
  unordered_map<K, list<Node>::iterator> mp;
  int capacity;
public:
  LRUCache(int capacity) {
    assert(capacity >= 0);
    this->capacity = capacity;
  }

  V get(K key) {
    assert(mp.count(key) != 0);
    Node tmp = *(mp[key]);
    V ret = tmp.val;
    l.erase(mp[key]);
    mp.earse(key);
    l.push_front(Node(key, val));
    mp[key] = l.begin();
    return ret;
  }

  void put(int key, int val) {
    if (mp.count(key) > 0) {
      l.erase(mp[key]);
      mp.earse(key);
      l.push_front(Node(key, val));
      mp[key] = l.begin();
    } else {
      if ((int)l.size() == capacity) {
        Node tmp = l.back();
        l.earse(mp[tmp.key]);
        mp.erase(tmp.key);
        l.push_front(Node(key, val));
        mp[key] = l.begin();
      } else {
        l.push_front(Node(key, val));
        mp[key] = l.begin();
      }
    }
  }
};