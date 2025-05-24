#include<bits/stdc++.h>
#define DEBUG
#define ll long long

using namespace std;

ll read() {
	ll x = 0, w = 1;char ch;
	while(!isdigit(ch = getchar())) if(ch == '-') w = -w;
	while(isdigit(ch)) {x = 10 * x + ch - '0'; ch = getchar();}
	return x * w;
}

int main(void) {
	ll r = read();
	vector<vector<ll>> tower(1);
	for(int i = 1; i <= r; i++) {
		vector<ll> l(1);
		for(int j = 1; j <= i; j++) {
			ll n = read();
			l.push_back(n);
		}
		tower.push_back(l);
	}
	ll size = tower.size();
	for(int i = size - 2; i >= 1; i--) {
		for(int j = i; j >= 1; j--) {
			tower[i][j] += max(tower[i+1][j], tower[i+1][j+1]);
		}
	}
	cout << tower[1][1];

	return 0;
}