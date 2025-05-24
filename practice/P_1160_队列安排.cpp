#include<bits/stdc++.h>
#define DEBUG
#define ll long long

using namespace std;

struct node {
	int val;
	struct node *next;
	struct node *prev;
};

ll read() {
	ll x = 0, w = 1;char ch;
	while(!isdigit(ch = getchar())) if(ch == '-') w = -w;
	while(isdigit(ch)) {x = 10 * x + ch - '0'; ch = getchar();}
	return x * w;
}

node* head;

node* initList() {
	node *h = new node;
	h->next = nullptr;
	h->prev = nullptr;
	h->val = -1;
	return h;
}

node* NinsertNode(node* a) {
	node* b = new node;
	b->next = a->next;
	b->prev = a;
	a->next = b;
	if(b->next != nullptr) b->next->prev = b;
	return b;
}

void NdelNode(node* a) {
	if(a == nullptr) return;
	if(a->next != nullptr) a->next->prev = a->prev;
	a->prev->next = a->next;
	delete a;
}
// void VdelNode(int a) {
// 	node* t = head;
// 	while(t->next != nullptr && t->next->val != a) t = t->next;
// 	if(t->next == nullptr) return;
// 	node* k = t->next->next;
// 	delete t->next;
// 	t->next = k;
// }

void freeNode() {
	node* h;
	while(head != nullptr) {
		h = head->next;
		delete head;
		head = h;
	}
}

int main(void) {
	int N = read();
	vector<node*> nodeSet(N+10);
	head = initList();
	node* a = NinsertNode(head);
	a->val = 1; nodeSet[1] = a;
	for(int i = 2; i <= N; i++) {
		int k = read(), p = read();
		node* t;
		if(p == 0) {
			node* m = nodeSet[k]->prev;
			t = NinsertNode(m);
			t->val = i;
		}
		else if(p == 1) {
			node* m = nodeSet[k];
			t = NinsertNode(m);
			t->val = i;
		}
		nodeSet[i] = t;
	}
	int M = read();
	for(int i = 0; i < M; i++) {
		int c = read(); NdelNode(nodeSet[c]); nodeSet[c] = nullptr;
	}
	node* r = head->next;
	while(r != nullptr) {
		cout << r->val << " ";
		r = r->next;
	}

	freeNode();
	return 0;
}