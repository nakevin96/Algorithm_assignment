// 2015005169_최윤석_11802
/*
	Insertion 알고리즘 코딩
	자료 배열의 모든 요소를 앞에서부터 차례대로 정렬된
	배열 부분과 비교하여 자신의 위치를 찾아 삽입히난 알고리즘.
	index=1 부터 시작하여 왼쪽 자료들과 비교
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	int numOfKeys, tmp;

	scanf("%d", &numOfKeys);
	int* numPtr = (int*)malloc(sizeof(int) * numOfKeys);

	for (i = 0; i < numOfKeys; i++) {
		scanf("%d", &numPtr[i]);
	}
	printf("\n");

	for (i = 1; i < numOfKeys; i++) {
		tmp = numPtr[i];
		j = i - 1;
		while ((numPtr[j] < tmp) && j >= 0) {
			numPtr[j + 1] = numPtr[j];
			j--;
		}
		numPtr[j + 1] = tmp;
	}

	for (i = 0; i < numOfKeys; i++) {
		printf("%d \n", numPtr[i]);
	}
	return 0;
}