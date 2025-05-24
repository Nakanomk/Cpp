#include<bits/stdc++.h>
#define MAXSIZE 100
typedef int ELemType;
typedef struct {
	ELemType data[MAXSIZE];
	int length;
} SeqList;

void initList(SeqList *L) {	//Initial list
	L -> length = 0;
}

int appendElem(SeqList *L, ElemType e) {	//add Element to the end
	if (L -> length >= MAXSIZE) {
		cout << "Full" << endl;
		return 0;
	}
	L-> data[L->length] = e;
	L->length++;
	return 1;
}

void listElem(SeqList *L) {	//print the elements
	for(int i = 0; i < L->length; i++) {
		cout << L->data[i] << " ";
	}
	cout << endl;
}

void insertElem(ELemType num, ELemType pos, SeqList *L) {
	if(pos <= L->length) {
		for(int i = L->length-1; i>= pos-1;i--) {
			L->data[i] = L->data[i-1];
		}
		L->data[pos-1] = num;
		L->length++;
	}
	else {
		cout << "Longer than the list." << endl;
	}
}

void delElem(ELemType pos, SeqList *L) {
	if(L->length >= pos) {
		for(int i = pos-1; i<L->length-1; i++) {
			L->data[i] = L->data[i+1];
		}
		L->length--;
	}
	else {
		cout << "Longer than the list." << endl;
	}
}

using namespace std;
int main() {
}