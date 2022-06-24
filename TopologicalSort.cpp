// 2015005169_√÷¿±ºÆ_11802

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct vertex {
	int color; // white = 0, gray=1, black =-1
	int start_time;
	int end_time;

}Vertex;

typedef struct vertexDetail {
	int out_degree;
	int* list;
}VertexDetail;

Vertex* vertex;
VertexDetail* vertexDetail;
int numOfVertex, time;
int* topo;
int topoNum = 0;
bool isDag = true;

void addEdge(int v1, int v2) {
	int cur = 0;

	for (int i = 0; i < numOfVertex; i++) {
		if (vertexDetail[v1].list[i] == 0)
			break;
		cur++;
	}
	vertexDetail[v1].list[cur] = v2;
}

void DFS_Visit(int v1) {

	int v2;
	time++;
	vertex[v1].color = 1;
	vertex[v1].start_time = time;

	for (int i = 0; i < vertexDetail[v1].out_degree; i++) {
		v2 = vertexDetail[v1].list[i];
		int color = vertex[v2].color;
		switch (color) {
		case 0:
			//white
			DFS_Visit(v2);
			break;
		case 1:
			//gray
			isDag = false;
			break;
		case -1:
			//black
			break;
		default:
			break;
		}
	}

	vertex[v1].color = -1;
	topo[numOfVertex - (topoNum++)] = v1;
	time++;
	vertex[v1].end_time = time;
}

void Sort(int* list, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (list[i] > list[j]) {
				int tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void DFS(void) {
	for (int i = 0; i <= numOfVertex; i++) {
		vertex[i].start_time = 0;
		vertex[i].end_time = 0;
		vertex[i].color = 0;
		Sort(vertexDetail[i].list, vertexDetail[i].out_degree);
	}

	time = 0;
	for (int i = 1; i <= numOfVertex; i++) {
		if (vertex[i].color == 0) {
			DFS_Visit(i);
		}
	}
}

int main(void) {
	int  numOfEdge;
	scanf("%d %d", &numOfVertex, &numOfEdge);
	vertexDetail = (VertexDetail*)malloc(sizeof(VertexDetail) * (numOfVertex + 1));
	for (int i = 1; i <= numOfVertex; i++) {
		vertexDetail[i].list = (int*)malloc(sizeof(int) * numOfVertex);
		vertexDetail[i].out_degree = 0;
	}
	for (int i = 1; i <= numOfVertex; i++) {
		for (int j = 0; j < numOfVertex; j++) {
			vertexDetail[i].list[j] = 0;
		}
	}
	vertex = (Vertex*)malloc(sizeof(Vertex) * (numOfVertex + 1));
	topo = (int*)malloc(sizeof(int) * (numOfVertex + 1));

	for (int i = 0; i < numOfEdge; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		addEdge(v1, v2);
		vertexDetail[v1].out_degree++;
	}
	DFS();


	if (isDag) {
		printf("1\n");
		for (int i = 1; i <= numOfVertex; i++) {
			printf("%d ", topo[i]);
		}
	}
	else {
		printf("0\n");
	}

	free(topo);
	free(vertex);
	for (int i = 1; i <= numOfVertex; i++) {
		free(vertexDetail[i].list);
	}
	free(vertexDetail);
	return 0;
}