#include<bits/stdc++.h>
#define int ElemType;
using namespace std;
//顺序表
typedef node {
	ElemType *elem;
	int length;
	int listsize;
} *elemlist; // Sqlist

if(listsize < length + 1) {
	elem = (ElemType *)realloc(elem, sizeof(ElemType) * (listsize+increment));
}

int elemdelete(*elemlist, int x) {
	for(int i = x - 1; i <= length - 2; i--) {
		elem[i] = elem[i + 1];
	}
	elemlist -> length--;
	return;
}// 删除不用考虑动态



int main() {

}

//链表
typedef chainlistnode {
	ElemType data;
	node* next; 
} *node;

node * head;

typedef struct{
	ElemType data;
	LinkList next;
}node, *Linklist;

先进先出链表

node* InsertList1(node *head, int e) {
	node* q = NULL;
	node* p = head;
	while(p && e > p -> data) {
		q = p;
		p = p-> next;
	}
	node * f = (node *)malloc(LENG);
	f -> data = e;
	f -> net - p;q -> next = f;
}
