// Assignment 6 :- Write a program for analysis of quick sort by using deterministic and randomized variant



#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int generateRandomPivot(int low, int high) {
	srand(time(NULL));
	return low + rand() % (high - low + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivotIndex = generateRandomPivot(low, high);
		int pivotValue = arr[pivotIndex];

		swap(&arr[pivotIndex], &arr[high]);

		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (arr[j] < pivotValue) {
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i+1], &arr[high]);

		quickSort(arr, low, i);
		quickSort(arr, i+2, high);
	}
}

int main() {
	int arr[] = {5, 2, 7, 3, 1, 6, 4, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Original array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	quickSort(arr, 0, n-1);

	cout << "\nSorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
