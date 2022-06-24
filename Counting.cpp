// 2015005169_√÷¿±ºÆ_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void countingSort(int* a, int* b, int* c, int N, int M);
void printNumOfKey(int a1, int b1, int* B, int N);

int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int* aArray = (int*)malloc(sizeof(int) * (N + 1));
	int* bArray = (int*)malloc(sizeof(int) * (N + 1));
	int* cArray = (int*)calloc(M + 1, sizeof(int));
	int* queryArray = (int*)malloc(sizeof(int) * (2 * K));
	for (int i = 0; i < 2 * K; i += 2) {
		scanf("%d %d", &queryArray[i], &queryArray[i + 1]);
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &aArray[i]);
	}

	countingSort(aArray, bArray, cArray, N, M);

	for (int i = 0; i < 2 * K; i += 2) {
		printNumOfKey(queryArray[i], queryArray[i + 1], bArray, N);
	}

	free(aArray);
	free(bArray);
	free(cArray);
	free(queryArray);
	return 0;
}

void countingSort(int* a, int* b, int* c, int N, int M) {
	for (int i = 1; i <= N; i++) {
		c[a[i]] = c[a[i]] + 1;
	}
	for (int j = 1; j <= M; j++) {
		c[j] = c[j - 1] + c[j];
	}
	for (int k = N; k >= 1; k--) {
		b[c[a[k]]] = a[k];
		c[a[k]] = c[a[k]] - 1;
	}
	return;
}

void printNumOfKey(int a1, int b1, int* B, int N) {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (B[i] >= a1 && B[i] <= b1) {
			count++;
		}
		if (B[i] > b1) {
			break;
		}
	}
	printf("%d\n", count);
	return;
}