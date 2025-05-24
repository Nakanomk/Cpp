#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define Elemtype int
typedef struct Node{
	Elemtype num;
	struct Node * next;
} QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
} Queue;

Queue * initQueue() {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	node -> num = 0;
	node -> next = NULL;
	q->front = node;
	q->rear = node;
	return q;
}

int queueInsertion(Queue* Q, Elemtype a) {
	QueueNode * newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if(newnode == NULL) return 1;
	Q->rear->next = newnode;
	Q->rear = newnode;
	Q->rear->num = a;
	Q->rear->next = NULL;
	return 0;
}

bool queueEmpty(Queue* Q) {
	if(Q->front == Q->rear) return true;
	return false;
}

Elemtype dequeue(Queue* Q) {
	if(queueEmpty(Q)) {
		cout << "empty!" << endl;
		exit(1);
	}
	Elemtype a = Q->front->num;
	QueueNode * r = Q->front;
	Q->front = Q->front->next;
	free(r);
	return a;
}

int freeQueue(Queue* Q) {
	while(Q->front != Q->rear) {
		QueueNode * r = Q->front;
		Q->front = Q->front->next;
		free(r);
	}
	free(Q->front);
	free(Q);
	return 0;
}

int main() {

}