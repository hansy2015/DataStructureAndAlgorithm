#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "../ArrayGenerator.h"
#include "../SortingHelper.h"

template<class T>

class MergeSort {
private:
	MergeSort() {

	}
public:
	static void sort(T* arr, int n) {
		sort(arr, 0, n - 1);
	}
private:
	static void sort(T* arr, int l, int r) {
		if (l >= r) {
			return;
		}
		int mid = (l + r) / 2;
		sort(arr, l, mid);
		sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}

	// 合并两个有序区间[l, mid] [mid + 1, r]
	static void merge(T* arr, int l, int mid, int r) {
		T* aux = new T[r - l + 1];
		copy(arr + l, arr + r + 1, aux);
		int i = l, j = mid + 1;
		// 为arr[k] 进行赋值
		for (int k = l ; k <= r; k++) {
			if (i > mid) {
				arr[k] = aux[j - l];
				j++;
			} else {
				if (j > r || aux[i - l] <= aux[j - l]) {
					arr[k] = aux[i - l];
					i++;
				} else {
					arr[k] = aux[j - l];
					j++;
				}
			}
		}
		delete[] aux;
	}
};


int main() {
	vector<int> dataSize = {10000, 100000};
	for (int n : dataSize) {
		int* arr = ArrayGenerator::generateRandomArray(n, n);
		clock_t startTime = clock();
		MergeSort<int>::sort(arr, n);
		assert(SortingHelper<int>::isSorted(arr, n));
		clock_t endTime = clock();
		printf("%.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);
	}
	return 0;
}