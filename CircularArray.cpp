//Algorithm : 	CircularArray is implemented just by storing a head index that points to the start if the
//				circ array instead of rotating as rotating is expensive.

#include <iostream>
using namespace std;

template <typename T>
class CircularArray {
private:
	int size;
	T* arr;
	int head; //Head is int as that refers to the index

public :
	CircularArray(int len) {
		size = len;
		arr = new T(size);
		head = 0;
	}
	int getArrIndex(int circIndex);
	void setArr(int circIndex, T val);
	T getArr(int circIndex);
	void rotate(int shiftRight);
	void print();
};

template <typename T>
int CircularArray<T> :: getArrIndex(int circIndex) {
	if (circIndex < 0) {
		circIndex += size;
	}
	return((head+circIndex)%size);
}

template <typename T>
void CircularArray<T> :: setArr(int circIndex, T val) {
	arr[getArrIndex(circIndex)] = val;
}

template <typename T>
T CircularArray<T> :: getArr(int circIndex) {
	return(arr[getArrIndex(circIndex)]);
}

template <typename T>
void CircularArray<T> :: rotate(int shiftRight) {
	head = getArrIndex(shiftRight);
}

template <typename T>
void CircularArray<T> :: print() {
	cout << "[ " ;
	for (int i=0; i<size; i++)
		cout << arr[getArrIndex(i)] << ", ";
	cout << " ]" << endl;
}

int main() {
	CircularArray<int>* circ = new CircularArray<int>(5);

	for (int i=0; i<5; i++)
		circ->setArr(i, i);
	circ->print();

	circ->rotate(1);
	circ->print();

	return 0;
}
