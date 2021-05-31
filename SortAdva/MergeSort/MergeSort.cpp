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
	static void sort2(T* arr, int n) {
		sort2(arr, 0, n - 1);
	}
	static void sort3(T* arr, int n) {
		sort3(arr, 0, n - 1);
	}
	static void sortBU(T* arr, int n) {
		sortBU(arr, 0, n - 1);
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


	static void sort2(T* arr, int l, int r) {
		if (l >= r) {
			return;
		}
		int mid = (l + r) / 2;
		sort2(arr, l, mid);
		sort2(arr, mid + 1, r);
		if (arr[mid] > arr[mid + 1]) { // 这一步在数组完全有序的时候是O(n)
			merge(arr, l, mid, r);
		}
	}


	static void sort3(T* arr, int l, int r) {
		// if (l >= r) {
		// 	return;
		// }
		if (r - l <= 25) { // 小于25个元素就用插入排序
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
		int mid = (l + r) / 2;
		sort3(arr, l, mid);
		sort3(arr, mid + 1, r);
		if (arr[mid] > arr[mid + 1]) { // 这一步在数组完全有序的时候是O(n)
			merge(arr, l, mid, r);
		}
	}

	static void sortBU(T* arr, int l, int r) {
		for (int sz = 1; sz <= r; sz += sz) {
			// 遍历合并的两个区间起始位置
			// 合并 [i, i + sz - 1] [i + sz, min(i + sz + sz - 1, r)]
			for (int i = 0; i + sz <= r; i += (sz + sz)) {
				if (sz * 2 <= 25) {
					int ll = i, rr = min(i + sz + sz - 1, r);
					for (int i = ll; i <= rr; i++) {
						T tmp = arr[i];
						int j;
						for (j = i; j - 1 >= ll; j--) {
							if (tmp < arr[j - 1]) {
								arr[j] = arr[j - 1];
							} else {
								break;
							}
						}
						arr[j] = tmp;
					}
					continue;
				}
				if (arr[i + sz - 1] > arr[i + sz]) {
					merge(arr, i, i + sz - 1, min(i + sz + sz - 1, r));
				}	
			}
		}
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
	vector<int> dataSize = {10000, 5000000};
	for (int n : dataSize) {
		int* arr = ArrayGenerator::generateRandomArray(n, n);
		//int* arr = ArrayGenerator::generateOrderedArray(n);
		int* arr2 = new int[n];
		int* arr3 = new int[n];
		int* arr4 = new int[n];
		copy(arr, arr + n, arr2);
		copy(arr, arr + n, arr3);
		copy(arr, arr + n, arr4);

		clock_t startTime = clock();
		MergeSort<int>::sort(arr, n);
		assert(SortingHelper<int>::isSorted(arr, n));
		clock_t endTime = clock();
		printf("sort : %.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);

		startTime = clock();
		MergeSort<int>::sort2(arr2, n);
		assert(SortingHelper<int>::isSorted(arr2, n));
		endTime = clock();
		printf("sort2 : %.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);

		startTime = clock();
		MergeSort<int>::sort3(arr3, n);
		assert(SortingHelper<int>::isSorted(arr3, n));
		endTime = clock();
		printf("sort3 : %.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);

		startTime = clock();
		MergeSort<int>::sortBU(arr4, n);
		assert(SortingHelper<int>::isSorted(arr4, n));
		endTime = clock();
		printf("sort4 : %.7f s\n", double(endTime - startTime) / CLOCKS_PER_SEC);
	}
	return 0;
}