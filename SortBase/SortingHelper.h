template<class T>
class SortingHelper {
private:
  SortingHelper() {}
public:
  static bool isSorted(T* arr, int n) {
    for (int i = 1; i < n; i++) {
      if (arr[i - 1] > arr[i]) {
        return false;
      }
    }
    return true;
  } 
};