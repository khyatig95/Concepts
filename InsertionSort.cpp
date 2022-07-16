//Time Complexity : O(N^2)
//Space Complexity : O(1)

#include <iostream>
using namespace std;

template <typename T>
void printArr(T* arr, int size) {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

template <typename T>
T* InsertionSort(T* arr, int size) {
	if (size == 0 || size == 1) {
		cout << "Array is empty or has just one element" << endl;
		return arr;
	}

	for (int i=1; i<size; i++) {
		cout << "i=" << i << endl;
		int j=i-1;
		int curr = arr[i];
		while (j>=0) {
			cout << "Comparing " << curr << " with " << arr[j] << endl;
			if (arr[j] < curr)
				break;
			arr[j+1] = arr[j]; //Shift by 1
			printArr(arr, size);
			j--;
			cout << "j=" << j << endl;
		}
		arr[j+1] = curr;
		printArr<T>(arr, size);
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
	res = InsertionSort<char>(arr, size);
	cout << "Sorted array: " << endl;
	printArr<char>(res, size);
}
