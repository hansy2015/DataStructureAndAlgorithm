#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "../ArrayGenerator.h"
#include "../SortingHelper.h"

using namespace std;

template<class T>

class InsertionSort {
private:
	InsertionSort() {}
public:
	static void sort(T* arr, int n) {
		for (int i = 0; i < n; i++) {
			int tmp = arr[i];
			int j;
			for (j = i; j - 1 >= 0; j--) {
				if (tmp < arr[j - 1]) {
					arr[j] = arr[j - 1]; 
				} else {
					break;
				}
			}
			arr[j] = tmp;
		}
	}
};

int main() {
	vector<int> dataSize = {10000, 100000};
	for (int n : dataSize) {
		int* arr = ArrayGenerator::generateRandomArray(n, n);
		clock_t startTime = clock();
		InsertionSort<int>::sort(arr, n);
		assert(SortingHelper<int>::isSorted(arr, n));
		clock_t endTime = clock();
		printf("%.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);
	}
	return 0;
}