#include<bits/stdc++.h>
using namespace std;

void swap(string &a, string &b) {
	string temp = a;
	a = b;
	b = temp;
}

void sortss(vector<string> ss) {
	for(int i = 0; i < ss.size(); i++) {
		for(int j = 0; j < ss.size() - i; j++) {
			if(ss[j] > ss[j - 1]) swap(ss[j], ss[j-1]);
		}
	}
	for(string s: ss) {
		cout << s << endl;
	}
}

int main() {
	vector<string> ss(10);
	for(int i = 0; i < 10; i++) {
		cin>> ss[i];
	}
	sortss(ss);

	system("pause");
	return 0;
}