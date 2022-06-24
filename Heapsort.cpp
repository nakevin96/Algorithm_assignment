// 2015005169_√÷¿±ºÆ_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
input n N keys
first print k biggest element
and second line, print the heap after extracting k biggest keys
*/
void buildMaxHeap(int* keyArray, int size);
void maxHeapify(int* keyArray, int size, int key);
void heapSort(int* keyArray, int size);
int main() {
	int numOfKeys, numOfK;

	//check the size of array and #of K
	scanf("%d %d", &numOfKeys, &numOfK);
	int* numPtr = (int*)malloc(sizeof(int) * (numOfKeys));
	int heapIndex = numOfKeys - 1;

	//push the value into the numPtr
	for (int i = 0; i < numOfKeys; i++) {
		scanf("%d", &numPtr[i]);
	}
	buildMaxHeap(numPtr, numOfKeys);
	heapSort(numPtr, numOfKeys);
	for (int i = 0; i < numOfK; i++) {
		printf("%d  ", numPtr[heapIndex--]);
	}
	printf("\n");
	for (int i = heapIndex; i >= 0; i--) {
		printf("%d  ", numPtr[i]);
	}
	free(numPtr);

	return 0;
}

void buildMaxHeap(int* keyArray, int size) {
	/*
	A.heap-size = A.length
	for i = floor(A.length/2) to 1
	Max-Heapify(A,i)
	*/
	int key = size / 2 - 1;
	for (key; key >= 0; key--) {
		maxHeapify(keyArray, size, key);
	}
	return;
}

void maxHeapify(int* keyArray, int size, int key) {
	/*
	compare self value with child value
	*/
	int left = key * 2 + 1;
	int right = key * 2 + 2;
	int big = key;
	int tmp;
	//select the big key from parent , left, right node
	if (left <size && keyArray[left] > keyArray[big]) {
		big = left;
	}
	if (right < size && keyArray[right] >keyArray[big]) {
		big = right;
	}

	if (key != big) {
		tmp = keyArray[big];
		keyArray[big] = keyArray[key];
		keyArray[key] = tmp;
		maxHeapify(keyArray, size, big);
	}
}

void heapSort(int* keyArray, int size) {
	int tmp;
	while (size > 1) {
		tmp = keyArray[0];
		keyArray[0] = keyArray[size - 1];
		keyArray[size - 1] = tmp;

		size--;
		maxHeapify(keyArray, size, 0);
	}
}