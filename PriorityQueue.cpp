// 2015005169_√÷¿±ºÆ_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int numPtr[100001];
void maxHeapifyUp(int* keyArray, int size, int key);
void maxHeapify(int* keyArray, int size, int key);
void extractionMax(int* keyArray, int* size);

int main() {
	int fInteger, sInteger, tInteger;
	int size = 0;
	int nSize = 0;
	while (1) {
		scanf("%d", &fInteger);
		switch (fInteger) {
		case 0:
			for (int i = nSize; i > size; i--) {
				printf("%d ", numPtr[i]);
			}
			printf("\n");
			for (int i = 1; i <= size; i++) {
				printf("%d ", numPtr[i]);
			}

			exit(0);
			break;
		case 1:
			scanf("%d", &sInteger);
			if (size < 1) {
				size = 1;
				nSize++;
				numPtr[nSize] = sInteger;
				if (nSize > size) {
					for (int i = nSize; i > size; i--) {
						int tmp = numPtr[i];
						numPtr[i] = numPtr[i - 1];
						numPtr[i - 1] = tmp;
					}
				}
			}
			else {
				size++;
				nSize++;
				numPtr[nSize] = sInteger;
				if (nSize > size) {
					for (int i = nSize; i > size; i--) {
						int tmp = numPtr[i];
						numPtr[i] = numPtr[i - 1];
						numPtr[i - 1] = tmp;
					}
				}
				maxHeapifyUp(numPtr, size, (int)(size / 2));
			}
			break;
		case 2:
			if (size < 1) {
				break;
			}
			extractionMax(numPtr, &size);
			break;
		case 3:
			scanf("%d %d", &sInteger, &tInteger);
			numPtr[sInteger] = tInteger;
			maxHeapify(numPtr, size, sInteger);
			if (sInteger > 1) {
				maxHeapifyUp(numPtr, size, (int)(sInteger / 2));
			}
			break;
		default:

			break;
		}
	}

	return 0;
}



void maxHeapifyUp(int* keyArray, int size, int key) {
	/*
	compare self value with child value
	*/
	int left = key * 2;
	int right = left + 1;
	int big = key;
	int tmp;
	//select the big key from parent , left, right node
	if (left <= size && keyArray[left] >= keyArray[big]) {
		big = left;
	}
	if (right <= size && keyArray[right] >= keyArray[big]) {
		big = right;
	}

	if (key != big) {
		tmp = keyArray[big];
		keyArray[big] = keyArray[key];
		keyArray[key] = tmp;
		if (key > 1) {
			maxHeapifyUp(keyArray, size, (int)(key / 2));
		}
	}
	return;
}

void maxHeapify(int* keyArray, int size, int key) {
	/*
	compare self value with child value
	*/
	int left = key * 2;
	int right = left + 1;
	int big = key;
	int tmp;
	//select the big key from parent , left, right node
	if (left <= size && keyArray[left] >= keyArray[big]) {
		big = left;
	}
	if (right <= size && keyArray[right] >= keyArray[big]) {
		big = right;
	}

	if (key != big) {
		tmp = keyArray[big];
		keyArray[big] = keyArray[key];
		keyArray[key] = tmp;
		maxHeapify(keyArray, size, big);
	}
	return;
}



void extractionMax(int* keyArray, int* size) {
	int tmp;
	tmp = keyArray[1];
	keyArray[1] = keyArray[*size];
	keyArray[*size] = tmp;
	*size = *size - 1;
	maxHeapify(keyArray, *size, 1);
	return;
}