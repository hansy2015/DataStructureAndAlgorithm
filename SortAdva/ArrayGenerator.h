#include <ctime>

using namespace std;

class ArrayGenerator {
private:
  ArrayGenerator() {}
public:
  static int* generateOrderedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = i;
    }
    return arr;
  }
  static int* generateRandomArray(int n, int bound) {
    int* arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
      arr[i] = rand() % bound;
    }
    return arr;
  }
};