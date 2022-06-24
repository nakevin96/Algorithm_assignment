// 2015005169_√÷¿±ºÆ_11802

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

using namespace std;
typedef struct w {
	int dest;
	int weight;
}W;

vector<W> weight[5001];

int N, M;

int minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX;
	int minIndex = 0;
	for (int i = 1; i <= N; i++) {
		if (!sptSet[i] && min > dist[i]) {
			minIndex = i;
			min = dist[i];
		}
	}
	return minIndex;
}


void dijkstra(int src) {
	int* dist = (int*)malloc(sizeof(int) * (N + 1));
	bool* sptSet = (bool*)malloc(sizeof(bool) * (N + 1));
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;

	for (int count = 0; count < N; count++) {
		int u = minDistance(dist, sptSet);
		for (int v = 1; v <= N; v++) {
			if (!sptSet[v]  && dist[u] != INT_MAX) {
				for (int k = 0; k < weight[u].size(); k++) {
					if (weight[u][k].dest == v) {
						if (dist[v] > dist[u] + weight[u][k].weight) {
							dist[v] = dist[u] + weight[u][k].weight;
						}
					}
				}
			}
		}
		sptSet[u] = true;
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] > max) max = dist[i];
	}
	printf("%d", max);
	free(dist);
	free(sptSet);
	return;
}
int main(void) {
	scanf("%d %d", &N, &M);
	int v1, v2, w;
	W tmp;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		tmp.dest = v2;
		tmp.weight = w;
		weight[v1].push_back(tmp);
	}
	dijkstra(1);

	return 0;
}