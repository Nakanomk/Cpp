#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int Elemtype;
typedef struct {
	Elemtype data[MAXSIZE];
	int front;
	int rear;
} Queue;

void initQueue(Queue *Q) {
	Q -> front = 0;
	Q -> rear = 0;
}

int queueFull(Queue *Q) {
	int slot = (Q->rear + 1) % MAXSIZE;
	if(slot == Q->front) {
		cout << "full!" << endl;
		return 0;
	}
	return 1;
}

int equeue(Queue *Q, Elemtype e) {
	if(!queueFull(Q)) {
		return 0;
	}
	Q -> data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}


int main() {

}