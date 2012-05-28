//============================================================================
// Name        : QuickSort.cpp
// Author      : Mikey
// Version     :
// Copyright   : opensource
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//returns an index into the array.
int findPivot(int*position)
{

}

//.
int partition(int * array, int left, int right, int pivotIndex){
	  int pivotValue = array[pivotIndex];
	  swap(array[pivotIndex], array[right]);  // Move pivot to end
	  int storeIndex = left;
	  for (int i = left; i< right; i++) {  // left ≤ i < right
		  if (array[i] < pivotValue) {
			  swap(array[i],array[storeIndex]);
			  storeIndex = storeIndex + 1;
		  }
	  }
	  swap(array[storeIndex],array[right]);  // Move pivot to its final place
	      return storeIndex;
}

void swap(int*x,int*y){
	int temp =0;
	temp = *x;
	*x = *y;
	*y = temp;
}

// performs quicksort
void qSort(int * array, int left, int right){
	// If the list has 2 or more items
	if (left < right)
	{
		// See "Choice of pivot" section below for possible choices
		int pivotIndex = 0; // choose any pivotIndex such that 'left' ≤ 'pivotIndex' ≤ 'right'

		// Get lists of bigger and smaller items and final position of pivot
		int pivotNewIndex = partition(array, left, right, pivotIndex);

		// Recursively sort elements smaller than the pivot
		qSort(array, left, (pivotNewIndex - 1));

		// Recursively sort elements at least as big as the pivot
		qSort(array, (pivotNewIndex + 1), right);
	}
}

int main() {
	int arraySize = 9;
	int beginning = 0;
	int end = arraySize - 1;
	int array[9] = {1,4,3,2,6,3,8,9,4};

	cout << "Sorting" << endl;

	qSort(array, beginning, end);
	cout << "New array value is: ";
	for (int i=0; i<arraySize; i++) {
		cout << array[i] << ",";
	}
	return 0;
}

