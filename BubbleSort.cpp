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
T* BubbleSort(T* arr, int size) {
	if (size == 0 || size == 1) {
		cout << "Array is empty or has just one element" << endl;
		return arr;
	}

	for (int i=0; i<size-1; i++) {
		cout << "Comparing " << arr[i] << " with " << arr[i+1] << endl;
		if (arr[i] > arr[i+1])
			swap(&arr[i], &arr[i+1]);
	}
	cout << endl;
	//Recursion with size-1 as at the end of each pass, we move the largest element at the correct position
	arr = BubbleSort(arr, size-1);
	return arr;
}

int main() {
	char arr[] = {'a', 'x', 'k', 'h', 's'};
	int size = sizeof(arr)/sizeof(arr[0]); //Will give number of elements in array
	char* res;
	cout << "Unsorted array: " << endl;
	printArr<char>(arr, size);
	res = BubbleSort<char>(arr, size);
	cout << "Sorted array: " << endl;
	printArr<char>(res, size);
}
