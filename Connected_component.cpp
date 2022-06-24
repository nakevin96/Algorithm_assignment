// 2015005169_√÷¿±ºÆ_11802

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int key;
	struct node* prev;
	struct node* next;
}NODE;

typedef struct set {
	NODE* head;
	NODE* tail;
	int setLength;
}SET;

static SET setlist[1001];
static NODE nodelist[1001];
static NODE nullNode;

void MAKE_SET(int x);
int FIND_SET(int x);
void UNION(int v1, int v2);

int main(void) {
	nullNode.key = 0;
	nullNode.prev = &nullNode;
	nullNode.next = &nullNode;
	int  N, M;
	scanf("%d %d", &N, &M);


	for (int i = 1; i <= N; i++) {
		MAKE_SET(i);
	}

	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		int s1 = FIND_SET(v1);
		int s2 = FIND_SET(v2);
		if (s1 != s2) {
			UNION(s1, s2);
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (nodelist[i].key == nodelist[i].prev->key) {
			count++;
		}
	}
	printf("%d", count);

	return 0;
}

void MAKE_SET(int x) {
	nodelist[x].key = x;
	nodelist[x].prev = &nodelist[x];
	nodelist[x].next = &nullNode;
	setlist[x].head = &nodelist[x];
	setlist[x].tail = &nodelist[x];
	setlist[x].setLength = 1;
}

int FIND_SET(int x) {
	return nodelist[x].prev->key;
}

void UNION(int s1, int s2) {
	int tmp;
	if (setlist[s1].setLength < setlist[s2].setLength) {
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	setlist[s1].tail->next = setlist[s2].head;
	setlist[s1].tail = setlist[s2].tail;
	setlist[s2].tail = setlist[s2].head;
	setlist[s1].setLength += setlist[s2].setLength;


	NODE* x = setlist[s2].head;

	for (int i = 0; i < setlist[s2].setLength; i++) {
		x->prev = setlist[s1].head;
		x = x->next;
	}

	setlist[s2].setLength = 1;
	return;
}