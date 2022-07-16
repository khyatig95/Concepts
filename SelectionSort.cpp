//Time Complexity : O(N^2)
//Space Complexity : O(1)

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
T* SelectionSort(T* arr, int size) {
	if (size == 0 || size == 1) {
		cout << "Array is empty or has just one element" << endl;
		return arr;
	}
	int min;
	for (int i=0; i<size-1; i++) {
		min = i;
		for (int j=i+1; j < size ; j++) {
			cout << "Comparing min " << arr[min] << " with " << arr[j] << endl;
			if (arr[min] > arr[j])
				min = j;
		}
		if (arr[min] != arr[i]) //Not the min we started out with
			swap(&arr[min], &arr[i]);
		cout << endl;
	}
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
	res = SelectionSort<char>(arr, size);
	cout << "Sorted array: " << endl;
	printArr<char>(res, size);
}
