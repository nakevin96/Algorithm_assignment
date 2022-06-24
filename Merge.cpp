// 2015005169_√÷¿±ºÆ_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void mergeD(int* numPtr, int p, int r, int nk);
void merge(int* numPtr, int p, int q, int r, int nk);

int main() {
	int i;
	int numOfKeys;
	scanf("%d", &numOfKeys);
	int* numPtr = (int*)malloc(sizeof(int) * numOfKeys);

	for (i = 0; i < numOfKeys; i++) {
		scanf("%d", &numPtr[i]);
	}
	printf("\n");

	mergeD(numPtr, 0, numOfKeys - 1, numOfKeys);

	for (i = 0; i < numOfKeys; i++) {
		printf("%d \n", numPtr[i]);
	}
	free(numPtr);
	return 0;
}

void mergeD(int* numPtr, int p, int r, int nk) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeD(numPtr, p, q, nk);
		mergeD(numPtr, q + 1, r, nk);
		merge(numPtr, p, q, r, nk);
	}
	return;
}

void merge(int* numPtr, int p, int q, int r, int nk) {
	int i = p;
	int j = q + 1;
	int k = p;
	int l;

	int* tmp = (int*)malloc(sizeof(int) * nk);

	while (i <= q && j <= r) {
		if (numPtr[i] >= numPtr[j]) {
			tmp[k++] = numPtr[i++];
		}
		else {
			tmp[k++] = numPtr[j++];
		}
	}
	while (i <= q) { tmp[k++] = numPtr[i++]; }
	while (j <= r) { tmp[k++] = numPtr[j++]; }
	for (l = p; l <= r; l++) { numPtr[l] = tmp[l]; }
	free(tmp);
	return;
}