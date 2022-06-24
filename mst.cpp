// 2015005169_√÷¿±ºÆ_11802

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
typedef struct vertex {
	int parent;
	int rank;
}Vertex;

typedef struct edge {
	int v1, v2;
	int weight;
}Edge;


Vertex* vertexlist;
Edge* edgelist;
Edge* edgeresult;

int findParent(int);
void connect(int, int);
void maxHeapify(int, int);
void buildMaxHeap(int);
void sort(int);
void make_kruscal(int, int);





int main(void) {
	int numOfVertex, numOfEdge;
	scanf("%d %d", &numOfVertex, &numOfEdge);
	vertexlist = (Vertex*)malloc(sizeof(Vertex) * (numOfVertex + 1));
	edgelist = (Edge*)malloc(sizeof(Edge) * (numOfEdge)+1);

	for (int i = 1; i <= numOfVertex; i++) {
		vertexlist[i].parent = i;
		vertexlist[i].rank = 0;
	}

	int v1, v2, w, tmp;
	for (int i = 0; i < numOfEdge; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		if (v2 < v1) {
			tmp = v1;
			v1 = v2;
			v2 = tmp;
		}
		edgelist[i].v1 = v1;
		edgelist[i].v2 = v2;
		edgelist[i].weight = w;
	}
	make_kruscal(numOfVertex, numOfEdge);
	free(edgelist);
	free(vertexlist);
	return 0;
}

int findParent(int v) {
	if (vertexlist[v].parent == v) {
		return v;
	}
	else {
		return vertexlist[v].parent=findParent(vertexlist[v].parent);
	}
}

void connect(int v1, int v2) {
	v1 = findParent(v1);
	v2 = findParent(v2);

	if (v1 == v2) {
		return;
	}

	if (vertexlist[v1].rank < vertexlist[v2].rank) {
		vertexlist[v1].parent = v2;
	}
	else {
		vertexlist[v2].parent = v1;
		if (vertexlist[v1].rank == vertexlist[v2].rank)
			vertexlist[v1].rank++;
	}
}

void maxHeapify(int index, int size) {
	Edge tmp;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largest = index;

	if (left < size && (edgelist[left].weight > edgelist[largest].weight)) {
		largest = left;
	}
	else if (left < size && (edgelist[left].weight == edgelist[largest].weight)) {
		if (edgelist[left].v1 > edgelist[largest].v1) {
			largest = left;
		}
		else if (edgelist[left].v1 == edgelist[largest].v1) {
			if (edgelist[left].v2 > edgelist[largest].v2)
				largest = left;
		}
		
	}

	if (right < size && (edgelist[right].weight > edgelist[largest].weight)) {
		largest = right;
	}
	else if (right < size && (edgelist[right].weight == edgelist[largest].weight)) {
		if (edgelist[right].v1 > edgelist[largest].v1) {
			largest = right;
		}
		else if (edgelist[right].v1 == edgelist[largest].v1) {
			if (edgelist[right].v2 > edgelist[largest].v2)
				largest = right;
		}
	}
	if (largest != index) {
		tmp = edgelist[largest];
		edgelist[largest] = edgelist[index];
		edgelist[index] = tmp;

		maxHeapify(largest, size);
	}
}

void buildMaxHeap(int numOfEdge) {
	for (int i = numOfEdge / 2; i >= 0; i--) {
		maxHeapify(i, numOfEdge);
	}
}

void sort(int numOfEdge) {
	Edge tmp;
	buildMaxHeap(--numOfEdge);
	for (int i = numOfEdge; i > 0; i--) {
		tmp = edgelist[i];
		edgelist[i] = edgelist[0];
		edgelist[0] = tmp;
		maxHeapify(0, i);
	}

}


void make_kruscal(int numOfVertex, int numOfEdge) {

	sort(numOfEdge);

	edgeresult = (Edge*)malloc(sizeof(Edge) * (numOfEdge)+1);
	int count = 0;

	for (int i = 0; i < numOfEdge; i++) {
		if (findParent(edgelist[i].v1) != findParent(edgelist[i].v2)) {
			connect(edgelist[i].v1, edgelist[i].v2);
			
			edgeresult[count].v1 = edgelist[i].v1;
			edgeresult[count].v2 = edgelist[i].v2;
			edgeresult[count].weight = edgelist[i].weight;
			count++;
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d %d %d \n", edgeresult[i].v1, edgeresult[i].v2, edgeresult[i].weight);
	}
	free(edgeresult);
}
