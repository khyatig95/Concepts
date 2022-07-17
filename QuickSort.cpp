//Time Complexity : O(NlogN)
//Space Complexity : O(logN) //due to recursion??

#include <iostream>
using namespace std;

template <typename T>
void swap(T* x, T* y) {
	cout << "Swapping " << *x << " and " << *y << endl;
	T temp = *x;
	*x = *y;
	*y = temp;
}

template <typename T>
void printArr(T* arr, int size) {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

template <typename T>
int partition(T* arr, int start, int end) {
	int size = end+1;
	int pivot = arr[(start+end)/2];
	cout << "Partition for start=" << start << " and end=" << end << " and pivot=" << pivot << endl;
	printArr<T>(arr, size);
	while(start <=  end) {
		while (arr[start] < pivot) start++; //Uptil start, all elements<pivot are at leftmost
		while(arr[end] > pivot) end--; //All elements>pivot are at rightmost
		if (start < end) {
			swap(&arr[start], &arr[end]);
			printArr<T>(arr, size);
			start++;
			end--;
		}
	}
	cout << endl;
	return start; //Elements uptil left are less than pivot
}

template <typename T>
void QuickSort(T* arr, int start, int end) {
	cout << "QuickSort for start=" << start << " and end=" << end << endl;
	int index = partition<T>(arr, start, end);
	if (start < index-1)
		QuickSort(arr, start, index-1);
	if (index < end)
		QuickSort(arr, index, end);
}

template <typename T>
T* QuickSort(T* arr, int size) {
	if (size == 0 || size == 1) {
		cout << "Array is empty or has just one element" << endl;
		return arr;
	}

	QuickSort<T>(arr, 0, size-1);
	return arr;
}

int main() {
	//int arr[] = {64, 34, 25, 12, 22, 11, 90};
	char arr[] = {'a', 'x', 'k', 'h', 's'};

	int size = sizeof(arr)/sizeof(arr[0]); //Will give number of elements in array
	//int* res;
	char* res;
	cout << "Unsorted array: " << endl;
	printArr<char>(arr, size);
	res = QuickSort<char>(arr, size);
	cout << "Sorted array: " << endl;
	printArr<char>(res, size);
}
