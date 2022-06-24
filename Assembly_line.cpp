// 2015005169_√÷¿±ºÆ_11802
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fast_way(int a[2][102], int t[2][102], int e[3], int x[3], int n);
void print_station(int** l, int resultl, int n);
int main(void) {
	int N;
	scanf("%d", &N);
	int e[3];
	scanf("%d %d", &e[1], &e[2]);
	int x[3];
	scanf("%d %d", &x[1], &x[2]);

	static int a[2][102];
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[0][i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[1][i]);
	}
	static int t[2][102];
	for (int i = 1; i < N; i++) {
		scanf("%d", &t[0][i]);
	}
	for (int i = 1; i < N; i++) {
		scanf("%d", &t[1][i]);
	}

	fast_way(a, t, e, x, N);

	return 0;
}

void fast_way(int a[2][102], int t[2][102], int e[3], int x[3], int n) {
	int** s = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		s[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	int** l = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		l[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	int results, resultl;

	s[0][1] = e[1] + a[0][1];
	s[1][1] = e[2] + a[1][1];
	for (int j = 2; j <= n; j++) {
		if (s[0][j - 1] <= s[1][j - 1] + t[1][j - 1]) {
			s[0][j] = s[0][j - 1] + a[0][j];
			l[0][j] = 1;
		}
		else {
			s[0][j] = s[1][j - 1] + t[1][j - 1] + a[0][j];
			l[0][j] = 2;
		}
		if (s[1][j - 1] <= s[0][j - 1] + t[0][j - 1]) {
			s[1][j] = s[1][j - 1] + a[1][j];
			l[1][j] = 2;
		}
		else {
			s[1][j] = s[0][j - 1] + t[0][j - 1] + a[1][j];
			l[1][j] = 1;
		}
	}

	if (s[0][n] + x[1] <= s[1][n] + x[2]) {
		results = s[0][n] + x[1];
		resultl = 1;
	}
	else {
		results = s[1][n] + x[2];
		resultl = 2;
	}
	printf("%d\n", results);

	for (int i = 0; i < 2; i++) {
		free(s[i]);
	}
	free(s);
	print_station(l, resultl, n);

}

void print_station(int** l, int resultl, int n) {
	int i = resultl;
	int* tmp = (int*)malloc(sizeof(int) * (n + 1));
	tmp[n] = i;
	for (int j = n; j >= 2; j--) {
		i = l[i - 1][j];
		tmp[j - 1] = i;
	}
	for (int k = 1; k <= n; k++) {
		printf("%d %d\n", tmp[k], k);
	}

	for (int k = 0; k < 2; k++) {
		free(l[k]);
	}
	free(l);
	free(tmp);
}