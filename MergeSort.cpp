//Time Complexity : O(NlogN)
//Space Complexity : O(N) -- Worst Case as if start!=0,
//the size of helper == size of end+1

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
void Merge(T* arr, int start, int mid, int end) {
	cout << "Merge with start=" << start << " and mid=" << mid << " and end=" << end << endl;
	T helper[end+1];
	//Copy the contents to a helper array
	for (int i=start; i<=end; i++)
		helper[i] = arr[i];
	cout << "Helper is " << endl;
	printArr<T>(helper, end+1);
	int left = start;
	int right = mid+1;
	int curr = start;

	while(left<=mid && right<=end) {
		cout << "helper_left= " << helper[left] << " and helper_right= " << helper[right] << endl;
		if (helper[left] < helper[right]) {
			arr[curr] = helper[left];
			left++;
		} else {
			arr[curr] = helper[right];
			right++;
		}
		curr++;
	}
	//Iterate for remaining left elements
	for (int i = left; i <= mid; i++) {
		arr[curr] = helper[i];
		curr++;
	}
	//No need to copy remaining right elements as they are already in the correct position in arr
	printArr<T>(arr, end+1);
}

template <typename T>
void MergeSort(T* arr, int start, int end) {
	cout << "MergeSort with start=" << start << " and end=" << end << endl;
	if (start < end) {
		int mid = (start+end)/2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid+1, end);
		Merge(arr, start, mid, end);
	}
}

template <typename T>
T* MergeSort(T* arr, int size) {
	if (size == 0 || size == 1) {
		cout << "Array is empty or has just one element" << endl;
		return arr;
	}
	MergeSort<T>(arr, 0, size-1);
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
	res = MergeSort<char>(arr, size);
	cout << "Sorted array: " << endl;
	printArr<char>(res, size);
}
