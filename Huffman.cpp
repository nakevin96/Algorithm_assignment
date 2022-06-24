// 2015005169_√÷¿±ºÆ_11802

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <string.h>


typedef struct HeapNode {
 
    char ch[5];
    int freq;

    HeapNode* left, * right;
}HeapNode;

typedef struct MinHeap {

    int size;
    int capacity;
    HeapNode** array;
}MinHeap;

static HeapNode* heapNodeStore[30001];
static char storeChar[30001][5];
static int arr[15];
static int huffmanTotal = 0;

HeapNode* makeNode(char *data, int freq){
   HeapNode* tmp= (HeapNode*)malloc(sizeof(HeapNode));
    tmp->left = tmp->right = NULL;
    strcpy(tmp->ch, data);
    tmp->freq = freq;

    return tmp;
}


MinHeap* makeMinHeap(int capacity){
  MinHeap* tmp= (MinHeap*)malloc(sizeof(MinHeap));
    tmp->size = 0;
    tmp->capacity = capacity;
    tmp->array = heapNodeStore;
    return tmp;
}
void swapHeap(HeapNode** a, HeapNode** b) {
    HeapNode* tmp = *a;
    *a = *b;
    *b = tmp;
}
void minHeapify(MinHeap* minHeap, int i){

    int min= i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[min]->freq) {
        min = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[min]->freq) {
        min = right;
    }

    if (min != i) {
        swapHeap(&minHeap->array[min],
            &minHeap->array[i]);
        minHeapify(minHeap, min);
    }
}


int isSizeOne(MinHeap* minHeap){
    return (minHeap->size == 1);
}
 
HeapNode* pop(MinHeap* minHeap){
    HeapNode* tmp = minHeap->array[0];
    minHeap->array[0]= minHeap->array[minHeap->size - 1];
    minHeap->size -= 1;
    minHeapify(minHeap, 0);
    return tmp;
}

void insert(MinHeap* minHeap,HeapNode* minHeapNode){
    minHeap->size+=1;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap){
    int n = minHeap->size - 1;
 
    for (int i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }      
}

int isLeaf(HeapNode* curr){
    return !(curr->left) && !(curr->right);
}

MinHeap* makeAndBuildMinHeap( int freq[], int size){

    MinHeap* minHeap = makeMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = makeNode(storeChar[i], freq[i]);
    }
        
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}
 
HeapNode* buildHuffmanTree(int freq[], int size){
    HeapNode* left, * right, * top;

    MinHeap* minHeap = makeAndBuildMinHeap(freq, size);

    while (!isSizeOne(minHeap)) {
        left = pop(minHeap);
        right = pop(minHeap);
        char tmp[5] = "tmp";
        top = makeNode(tmp, left->freq + right->freq);
        top->left = left;
        top->right = right;

        insert(minHeap, top);
    }

    return pop(minHeap);
}

void calHuffmanCodes(HeapNode* curr, int arr[], int top){

    if (curr->left) {
        arr[top] = 0;
        calHuffmanCodes(curr->left, arr, top + 1);
    }

    if (curr->right) {
        arr[top] = 1;
        calHuffmanCodes(curr->right, arr, top + 1);
    }

    
    if (isLeaf(curr)){
        huffmanTotal += top * curr->freq;
    }
}


void HuffmanCodes(int freq[], int size){
    HeapNode* root = buildHuffmanTree(freq, size);

    int top = 0;

    calHuffmanCodes(root, arr, top);
}


int main()
{
    int N;
    scanf("%d", &N);
    int * freq = (int *)malloc(sizeof(int)*N);
    int totalfreq = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s %d", storeChar[i], &freq[i]);
    }
    scanf("%d", &totalfreq);
    int fixedLong = (int)(log(N) / log(2)) + 1;
    printf("%d\n", totalfreq*fixedLong);
    
    HuffmanCodes(freq, N);
    printf("%d\n", huffmanTotal);
    free(freq);
    return 0;
}