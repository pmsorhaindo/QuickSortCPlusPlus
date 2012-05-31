//============================================================================
// Name        : QuickSort.cpp
// Author      : Mikey
// Version     :
// Copyright   : opensource
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// partition
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

	  /*cout << "New array value is: ";
	  			for (int i=0; i<9; i++) {
	  				cout << array[i] << ",";
	  			}
	  		cout <<"\n";*/

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
		// this line was the problem I left it as 0 (needs a random between left and right tbh. [soon]
		int pivotIndex = left+1; // choose any pivotIndex such that 'left' ≤ 'pivotIndex' ≤ 'right'

		// Get lists of bigger and smaller items and final position of pivot
		int pivotNewIndex = partition(array, left, right, pivotIndex);

		// Recursively sort elements smaller than the pivot
		qSort(array, left, (pivotNewIndex - 1));

		// Recursively sort elements at least as big as the pivot
		qSort(array, (pivotNewIndex + 1), right);
	}
}

int main() {

	/*int arraySize = 67;
	int beginning = 0;
	int end = arraySize-1;

	int array[67] = {1,4,3,2,6,3,8,9,4,20,65,3,7,48,65,2,38,4,75,60,32,48,7,62,13,87,5,62,30,8,75,60,87,16,92,38,17,-4,42,3,45,68,77,82,63,48,72,36,84,76,23,89,76,23,79,54,92,36,74,69,28,71,9,48,63,25};*/


	int arraySize = 9;
	int beginning = 0;
	int end = arraySize-1;
	int array[9] = {1,4,3,2,6,3,8,9,4};

	cout << "Sorting" << "\n";

	qSort(array, beginning, end);
	cout << "New array value is: ";
	for (int i=0; i<arraySize; i++) {
		cout << array[i] << ",";
	}
	cout <<"\n";
	return 0;
}

