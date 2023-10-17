// Implement merge sort and multithreaded merge sort. Compare time required by both the algorithms. Also analyze the performance of each algorithm for the best case and the worst case.




#include <iostream>
#include <pthread.h>
#include <time.h>

#define MAX 20
#define THREAD_MAX 4

using namespace std;


int a[MAX];
int part = 0;


void merge(int low, int mid, int high)
{
	int* left = new int[mid - low + 1];
	int* right = new int[high - mid];

	
	int n1 = mid - low + 1, n2 = high - mid, i, j;


	for (i = 0; i < n1; i++)
		left[i] = a[i + low];

	
	for (i = 0; i < n2; i++)
		right[i] = a[i + mid + 1];

	int k = low;
	i = j = 0;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];
	}


	while (i < n1) {
		a[k++] = left[i++];
	}

	
	while (j < n2) {
		a[k++] = right[j++];
	}
}


void merge_sort(int low, int high)
{
	
	int mid = low + (high - low) / 2;
	if (low < high) {

		
		merge_sort(low, mid);

		
		merge_sort(mid + 1, high);

		
		merge(low, mid, high);
	}
}

void* merge_sort(void* arg)
{
	
	int thread_part = part++;

	
	int low = thread_part * (MAX / 4);
	int high = (thread_part + 1) * (MAX / 4) - 1;

	// evaluating mid point
	int mid = low + (high - low) / 2;
	if (low < high) {
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}


int main()
{

	for (int i = 0; i < MAX; i++)
		a[i] = rand() % 100;

	
	clock_t t1, t2;

	t1 = clock();
	pthread_t threads[THREAD_MAX];

	
	for (int i = 0; i < THREAD_MAX; i++)
		pthread_create(&threads[i], NULL, merge_sort,
										(void*)NULL);

	for (int i = 0; i < 4; i++)
		pthread_join(threads[i], NULL);

	
	merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
	merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1);
	merge(0, (MAX - 1)/2, MAX - 1);

	t2 = clock();


	cout << "Sorted array: ";
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";



	return 0;
}


// Time Complexity: O(nLogn)
// Space Complexity:  O(n)
