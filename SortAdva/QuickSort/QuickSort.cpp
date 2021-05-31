#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "../ArrayGenerator.h"
#include "../SortingHelper.h"


template<class T>
class QuickSort {
private:
	QuickSort() {}
public:
	static void sort(T* arr, int n) {
		sort(arr, 0, n - 1);
	}
private:
	static void sort(T* arr, int l, int r) {
		if (r - l <= 25) {
			for (int i = l; i <= r; i++) {
				T tmp = arr[i];
				int j;
				for (j = i; j - 1 >= l; j--) {
					if (tmp < arr[j - 1]) {
						arr[j] = arr[j - 1];
					} else {
						break;
					}
				}
				arr[j] = tmp;
			}
			return;
		}
		int p = parition(arr, l, r);
		sort(arr, l, p);
		sort(arr, p + 1, r);
	}
	static int parition(T* arr, int l, int r) {
		// arr[l + 1...j] < v; arr[j + 1...i] > v
		srand(time(0));
		int p = rand() % (r - l + 1) + l;
		swap(arr[l], arr[p]);
		int j = l;
		for (int i = l + 1; i <= r; i++) {
			if (arr[i] < arr[l]) {
				j++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[l], arr[j]);
		return j;
	}
};

int main() {
	int n = 1000000;
	int* arr = ArrayGenerator::generateRandomArray(n, n);
	clock_t startTime = clock();
	QuickSort<int>::sort(arr, n);
	assert(SortingHelper<int>::isSorted(arr, n));
	clock_t endTime = clock();
	printf("sort : %.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);

	return 0;
}