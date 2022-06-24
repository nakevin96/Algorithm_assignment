// 2015005169_최윤석_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cal_rn(int* p, int n);

int main() {
	//첫번째 줄에 길이 입력
	//두번째 줄에 위의 길이 만큼의 p값 입력
	int length;
	int* price;
	scanf("%d", &length);
	price = (int*)malloc(sizeof(int) * (length + 1));

	for (int i = 1; i <= length; i++) {
		scanf("%d", &price[i]);
	}

	cal_rn(price, length);

	free(price);
	return 0;
}

void cal_rn(int* p, int n) {
	int* r = (int*)malloc(sizeof(int) * (n + 1));
	int* s = (int*)malloc(sizeof(int) * (n + 1));
	int q;

	r[0] = 0;
	for (int j = 1; j <= n; j++) {
		q = -100000;
		for (int i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	printf("%d\n", r[n]);
	while (n > 0) {
		printf("%d ", s[n]);
		n = n - s[n];
	}
	printf("\n");
	free(r);
	free(s);
}