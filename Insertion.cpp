// 2015005169_������_11802
/*
	Insertion �˰��� �ڵ�
	�ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� ���ĵ�
	�迭 �κа� ���Ͽ� �ڽ��� ��ġ�� ã�� �������� �˰���.
	index=1 ���� �����Ͽ� ���� �ڷ��� ��
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