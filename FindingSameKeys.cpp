// 2015005169_√÷¿±ºÆ_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void countingSort(int* a, int* b, int* c, int N, int M);
void printNumOfKey(int a1, int b1, int* B, int N);

int main(void) {
	int N, M;
	int count = 0;
	scanf("%d %d", &N, &M);

	int* nArray = (int*)malloc(sizeof(int) * N);
	int* mArray = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nArray[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &mArray[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (nArray[i] == mArray[j]) {
				count++;
			}
		}
	}
	printf("%d", count);
	free(nArray);
	free(mArray);

	return 0;
}
