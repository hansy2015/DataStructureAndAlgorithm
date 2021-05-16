#include <iostream>
#include <string>
#include <cassert>
#include "../ArrayGenerator.h"
#include "../SortingHelper.h"

using namespace std;

struct Student {
  string name;
  int score;
  Student(string name, int score) {
    this->name = name;
    this->score = score;
  }
  /*
    返回值 operator运算符(参数列表){}

    1、内置类型的操作符不能被重载
    2、不能为内置类型定义其他的操作符
    3、操作符重载不能改变操作符的优先级
    4、操作数个数不能改变

  */
  bool operator== (const Student& other) const {
    return name == other.name && score == other.score;
  }

  bool operator< (const Student& other) const { // 分数越高的排名越靠前
    if (score < other.score) {
      return true;
    } else {
      return false;
    }
  }

  friend ostream& operator<<(ostream &out, Student &s);
};

ostream &operator<<(ostream &out, Student &s) {
  out << s.name << " " << s.score;
  return out;
}


template<typename T>
class SelectionSort {
private:  
  SelectionSort() {}
public:
  // arr[0 ... i) 是有序的； arr[i...n)是无序的
  static void sort(T* arr, int n) {
    for (int i = 0; i < n; i++) {
      // 选择arr[i ... n) 中的最小值的索引
      int minIndex = i;
      for (int j = i; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
          minIndex = j;
        }
      }
      swap(arr[i], arr[minIndex]);
    }
  }
};

void test1() {
  int n = 10000;
  int* arr = ArrayGenerator::generateRandomArray(n, n);
  clock_t startTime = clock();
  SelectionSort<int>::sort(arr, n);
  assert(SortingHelper<int>::isSorted(arr, n));
  clock_t endTime = clock();
  printf("%.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);
}

void test2 () {
  Student* students = new Student[6] {Student("a", 1), Student("b", 4), Student("c", 2), Student("d", 3), Student("e", 6), Student("f", 5)};
  SelectionSort<Student>::sort(students, 6);
  for (int i = 0; i < 6; i++) {
    cout << students[i] << " ";
  }
  cout << endl;
}

int main() {
  test1();
  return 0;
}