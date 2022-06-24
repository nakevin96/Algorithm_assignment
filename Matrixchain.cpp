// 2015005169_최윤석_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_optimal_parens(int s[102][102], int i, int j);
int matchain(int s[102][102], int* p, int N) {
	int j, q;
	int** m = (int**)malloc(sizeof(int*) * (N + 1));
	m[0] = (int*)malloc(sizeof(int) * (N + 1) * (N + 1));
	for (int i = 1; i <= N; i++) {
		m[i] = m[i - 1] + (N + 1);
	}

	for (int i = 1; i <= N; i++) {
		m[i][i] = 0;
	}

	for (int l = 2; l <= N; l++) {
		for (int i = 1; i <= N - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = 1000000;
			for (int k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	int result = m[1][N];

	free(m[0]);
	free(m);
	return result;
}

int main(void) {
	int N;

	scanf("%d", &N);

	//p배열 설정
	int* p = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i <= N; i++) {
		scanf("%d", &p[i]);
	}

	static int s[102][102];


	int result = matchain(s, p, N);
	printf("%d\n", result);
	print_optimal_parens(s, 1, N);



	free(p);
	return 0;
}


void print_optimal_parens(int s[102][102], int i, int j) {
	if (i == j) {
		printf("%d ", i);
	}
	else {
		printf("(");
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		printf(")");
	}
}