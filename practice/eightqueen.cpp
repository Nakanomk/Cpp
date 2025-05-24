#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
typedef long long ll;
set<string> ss;
ll n, counter = 0;
class Queen {
	public:
		ll x;
		ll y;
		Queen(ll x, ll y) : x(x), y(y) {};
		bool isNotValid(Queen q) {
			return (q.x == this->x) || (q.y == this->y) || (abs(q.x - this->x) == abs(q.y - this->y));
		}
};

void saveChess(vector<Queen> &qs) {
	string s;
	for(Queen q: qs) {
		string ts = to_string(q.x + 1);
		if(ts.length() > 1) ts[0] = 'x';
		s += ts;
		s += ' ';
	}
	ss.insert(s);
	return;
}
void dfs(ll pos, ll layer, vector<Queen> &qs) {
	if(layer == -1) {
		for(ll i = 0; i < n; i++) dfs(i, layer+1, qs);
		return;
	}
	if(layer == n) {
		counter++;
		saveChess(qs);
		return;
	}
	Queen newQ(pos, layer);
	for(ll i = 0; i < layer; i++) {
		if(qs[i].isNotValid(newQ)) return;
	}
	qs.push_back(newQ);
	if(layer+1 != n) for(ll i = 0; i < n; i++) dfs(i, layer+1, qs);
	else dfs(0,layer+1,qs);
	qs.pop_back();
}

int main() {
	cin >> n;
	vector<Queen> qs;
	dfs(0, -1, qs);
	int c = 0;
	for(auto iter1 = ss.begin(); c < 3; c++, iter1++) {
		for(char i: *iter1) {
			if(i == 'x') i = '1';
			putchar(i);
		}
		putchar('\n');
	}
	cout << counter;
	system("pause");
	return 0;
}