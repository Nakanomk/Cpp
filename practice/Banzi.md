### 快读

~~~Cpp
#define ll long long
inline ll read() {
	ll s = 0, w = 1;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') w = -1; c = getchar();}
	while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	return s * w;
}
~~~

### 高精加法

~~~cpp
struct node {
	int c[N], l;
	node() {l = 0;}
	void print() {
		for (int i = l; i >= 1; i--) printf("%d", c[i]);
		printf("\n");
	}
} a, b, ans;
node operator +(const node &a, const node &b) {
	node res; res.l = max(a.l, b.l);
	for (int i = 1; i <= res.l; i++) res.c[i] = a.c[i] + b.c[i];
	for (int i = 1; i < res.l; i++) res.c[i + 1] += res.c[i] / 10, res.c[i] %= 10;
	while (res.c[res.l] > 9) res.c[res.l + 1] = res.c[res.l] / 10, res.c[res.l] %= 10, res.l++;
	while (res.c[res.l] == 0 && res.l > 1) res.l--;
	return res;
}
~~~

### 高精减法

~~~cpp
struct node {
	int c[N], l;
	node() {l = 0;}
	void print() {
		for (int i = l; i >= 1; i--) printf("%d", c[i]);
		printf("\n");
	}
} a, b, ans;
node operator -(const node &a, const node &b) {
	node res; res.l = max(a.l, b.l);
	for (int i = 1; i <= res.l; i++) res.c[i] = a.c[i] - b.c[i];
	for (int i = 1; i < res.l; i++)
		if (res.c[i] < 0) res.c[i] += 10, res.c[i + 1]--;
	while (res.c[res.l] == 0 && res.l > 1) res.l--;
	return res;
}
bool operator >(const node &a, const node &b) {
	if (a.l != b.l) return a.l > b.l;
	for (int i = a.l; i >= 1; i--) 
		if (a.c[i] != b.c[i]) return a.c[i] > b.c[i];
	return 0;
}

if (b > a) printf("-"), ans = b - a;
else ans = a - b;
~~~

### 高精乘法

~~~cpp
struct node {
	int c[N], l;
	node() {l = 0;}
	void print() {
		for (int i = l; i >= 1; i--) printf("%d", c[i]);
		printf("\n");
	}
} a, b, ans;
node operator *(const node &a, const node &b) {
	node res; res.l = a.l + b.l - 1;
	for (int i = 1; i <= a.l; i++)
		for (int j = 1; j <= b.l; j++)
			res.c[i + j - 1] += a.c[i] * b.c[j];
	for (int i = 1; i < res.l; i++) res.c[i + 1] += res.c[i] / 10, res.c[i] %= 10;
	while (res.c[res.l] > 9) res.c[res.l + 1] += res.c[res.l] / 10, res.c[res.l] %= 10, res.l++;
	while (res.c[res.l] == 0 && res.l > 1) res.l--;
	return res;
}
~~~

### 树状数组

~~~cpp
// 此处为查询区间和的树状数组。
int bit[500010];
void add(int k, int x) {
	while (k <= n) {
		bit[k] += x;
		k += lowbit(k);
	}
}
int ask(int k) {
	int res = 0;
	while (k) {
		res += bit[k];
		k -= lowbit(k);
	}
	return res;
}

~~~

### 线段树

~~~cpp
// 此处为区间修改区间查询区间和的线段树。
struct SegmentTree {
	ll sum[N << 2], lazy[N << 2];
	int l[N << 2], r[N << 2];
	void update(int rt) {
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
	void pushdown(int rt) {
		if (!lazy[rt]) return ;
		sum[rt << 1] += (r[rt << 1] - l[rt << 1] + 1) * lazy[rt], lazy[rt << 1] += lazy[rt];
		sum[rt << 1 | 1] += (r[rt << 1 | 1] - l[rt << 1 | 1] + 1) * lazy[rt], lazy[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
		update(rt);
	}
	void build(int rt, int L, int R) {
		l[rt] = L, r[rt] = R;
		if (L == R) {
			sum[rt] = a[L];
			return ;
		}
		int mid = L + R >> 1;
		build(rt << 1, L, mid), build(rt << 1 | 1, mid + 1, R);
		update(rt);
	}
	void change(int rt, int L, int R, int x) {
		if (L <= l[rt] && r[rt] <= R) {
			sum[rt] += (r[rt] - l[rt] + 1) * x;
			lazy[rt] += x;
			return ;
		}
		pushdown(rt);
		if (L <= r[rt << 1]) change(rt << 1, L, R, x);
		if (l[rt << 1 | 1] <= R) change(rt << 1 | 1, L, R, x);
		update(rt);
	}
	ll query(int rt, int L, int R) {
		if (L <= l[rt] && r[rt] <= R) return sum[rt];
		pushdown(rt);
		ll res = 0;
		if (L <= r[rt << 1]) res += query(rt << 1, L, R);
		if (l[rt << 1 | 1] <= R) res += query(rt << 1 | 1, L, R);
		return res;
	}
} tree;

~~~

### 动态开点线段树

~~~cpp
// 此处为区间修改区间查询区间和的动态开点线段树。
struct SegmentTree {
	int l[N << 1], r[N << 1], ls[N << 1], rs[N << 1], cnt; ll sum[N << 1], lazy[N << 1];
	void update(int rt) {sum[rt] = sum[ls[rt]] + sum[rs[rt]];}
	int build(int L, int R) {
		cnt++;
		l[cnt] = L, r[cnt] = R, sum[cnt] = 0, lazy[cnt] = 0;
		return cnt;
	}
	void pushdown(int rt) {
		if (lazy[rt] == 0) return ;
		lazy[ls[rt]] += lazy[rt], lazy[rs[rt]] += lazy[rt];
		sum[ls[rt]] += lazy[rt] * (r[ls[rt]] - l[ls[rt]] + 1);
		sum[rs[rt]] += lazy[rt] * (r[rs[rt]] - l[rs[rt]] + 1);
		lazy[rt] = 0;
	}
	void change(int rt, int L, int R, int x) {
		if (r[rt] < L || R < l[rt]) return ;
		if (L <= l[rt] && r[rt] <= R) {sum[rt] += x * (r[rt] - l[rt] + 1); lazy[rt] += x; return ;}
		pushdown(rt);
		int mid = l[rt] + r[rt] >> 1;
		if (L <= mid) {
			if (!ls[rt]) ls[rt] = build(l[rt], mid);
			change(ls[rt], L, R, x);
		}
		if (mid + 1 <= R) {
			if (!rs[rt]) rs[rt] = build(mid + 1, r[rt]);
			change(rs[rt], L, R, x);
		}
		update(rt);
	}
	ll query(int rt, int L, int R) {
		if (r[rt] < L || R < l[rt]) return 0;
		if (L <= l[rt] && r[rt] <= R) return sum[rt];
		pushdown(rt);
		int mid = l[rt] + r[rt] >> 1; ll res = 0;
		if (L <= mid) {
			if (!ls[rt]) ls[rt] = build(l[rt], mid);
			res += query(ls[rt], L, R);
		}
		if (mid + 1 <= R) {
			if (!rs[rt]) rs[rt] = build(mid + 1, r[rt]);
			res += query(rs[rt], L, R);
		}
		return res;
	}
} tree;

~~~

### 扫描线

~~~cpp
//此处为统计矩阵总覆盖面积的扫描线
const int N = 100010;
int n; 
struct node {
	int l, r, h, tag;
	bool operator <(const node &a) {return h < a.h;}
} lne[N << 1]; int lcnt;
int tx[N << 1], tcnt;
struct SegmentTree {
	int l[N << 4], r[N << 4]; ll sum[N << 4], len[N << 4];
	void update(int rt) {
		if (sum[rt]) len[rt] = tx[r[rt] + 1] - tx[l[rt]];
		else len[rt] = len[rt << 1] + len[rt << 1 | 1];
	}
	void build(int rt, int L, int R) {
		l[rt] = L, r[rt] = R;
		if (L == R) {sum[rt] = len[rt] = 0; return ;}
		int mid = L + R >> 1;
		build(rt << 1, L, mid), build(rt << 1 | 1, mid + 1, R);
		update(rt);
	}
	void add(int rt, int L, int R, int x) {
		if (tx[r[rt] + 1] <= L || R <= tx[l[rt]]) return ;
		if (L <= tx[l[rt]] && tx[r[rt] + 1] <= R) {sum[rt] += x; update(rt); return ;}
		add(rt << 1, L, R, x), add(rt << 1 | 1, L, R, x);
		update(rt);
	}
} tree;

n = read();
	for (int i = 1; i <= n; i++) {
		int xa = read(), ya = read(), xb = read(), yb = read();
		tx[++tcnt] = xa, tx[++tcnt] = xb;
		lne[++lcnt].l = xa, lne[lcnt].r = xb, lne[lcnt].h = ya, lne[lcnt].tag = 1;
		lne[++lcnt].l = xa, lne[lcnt].r = xb, lne[lcnt].h = yb, lne[lcnt].tag = -1;
	} 
	sort(tx + 1, tx + 1 + tcnt); tcnt = unique(tx + 1, tx + 1 + tcnt) - tx - 1;
	sort(lne + 1, lne + 1 + lcnt);
	tree.build(1, 1, tcnt - 1); 
	for (int i = 1; i < lcnt; i++) {
		tree.add(1, lne[i].l, lne[i].r, lne[i].tag);
		ans += tree.len[1] * (lne[i + 1].h - lne[i].h); 
	}
	printf("%lld\n", ans);

~~~

### 堆

~~~cpp
ll q[N], cnt;
void pushup(int id) {
	while (id > 1) {
		if (q[id] >= q[id >> 1]) break;
		swap(q[id], q[id >> 1]);
		id >>= 1;
	}
}
void movedown() {
	int id = 1;
	while (id << 1 <= cnt) {
		if ((id << 1 | 1) <= cnt) {
			if (q[id] < min(q[id << 1], q[id << 1 | 1])) break;;
			if (q[id << 1] < q[id << 1 | 1]) swap(q[id], q[id << 1]), id <<= 1;
			else swap(q[id], q[id << 1 | 1]), id = id << 1 | 1;
		}
		else {
			if (q[id] > q[id << 1]) swap(q[id], q[id << 1]);
			break;
		}
	}
}
void add(ll x) {
	q[++cnt] = x;
	pushup(cnt);
}
void pop() {
	swap(q[1], q[cnt]);
	cnt--;
	movedown();
}
~~~

### 并查集

~~~cpp
struct Disjoint_Set {
	int p[N], size[N];
	void build() {
		for (int i = 1; i <= n; i++) p[i] = i, size[i] = 1;
	}
	int root(int x) {
		if (p[x] != x) return p[x] = root(p[x]);
		return x;
	}
	void merge(int x, int y) {
		x = root(x), y = root(y);
		if (size[x] > size[y]) swap(x, y);
		p[x] = y;
		size[y] += size[x];
	}
	bool check(int x, int y) {
		x = root(x), y = root(y);
		return x == y;
	}
} a;
~~~

### ST表

~~~cpp
// 代码实现查询区间 $[l, r]$ 的区间最大值
for (int i = 1; i <= n; i++) st[0][i] = a[i];
for (int j = 1; j <= lg; j++) {
	for (int i = 1; i <= n - (1 << j) + 1; i++) {
		st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
	}
}
int l, r, lg2, len;
for (int i = 1; i <= m; i++) {
	l = read(), r = read();
	lg2 = log2(r - l + 1);
	len = 1 << lg2;
	printf("%d\n", max(st[lg2][l], st[lg2][r - len + 1]));
}
~~~

### 边链表

~~~cpp
const int N = 100010;
int last[N], cnt;
struct edge {
	int to, next, w;
} e[N << 1];
void addedge(int x, int y, int w) {
	e[++cnt].to = y;
	e[cnt].next = last[x];
	e[cnt].w = w;
	last[x] = cnt;
}
~~~

### LCA（Tarjan）法

~~~cpp
struct Disjoint_Set {
	int p[N], size[N];
	void build() {
		for (int i = 1; i <= n; i++) p[i] = i, size[i] = 1;
	}
	int root(int x) {
		if (p[x] != x) return p[x] = root(p[x]);
		return x;
	}
	void merge(int x, int y) {
		x = root(x), y = root(y);
		if (size[x] > size[y]) swap(x, y);
		p[x] = y;
		size[y] += size[x];
	}
	bool check(int x, int y) {
		x = root(x), y = root(y);
		return x == y;
	}
} a;
int last[N], cnt;
struct edge {
	int to, next;
} e[N << 1];
void addedge(int x, int y) {
	e[++cnt].to = y;
	e[cnt].next = last[x];
	last[x] = cnt;
}
struct node {
	int x, y, ans;
} ask[N];
vector <int> g[N];
int p[N];
bool vis[N];
int r[N];
void dfs(int x, int f) {
	p[x] = f;
	for (int i = last[x]; i; i = e[i].next) {
		int v = e[i].to;
		if (v == f) continue;
		vis[v] = 1;
		for (int j : g[v]) {
			int o = ask[j].x;
			if (o == v) o = ask[j].y;
			if (!vis[o]) continue;
			ask[j].ans = r[a.root(o)]; 
		}
		dfs(v, x);
		a.merge(x, v);
		r[a.root(x)] = x;
	}
}
~~~

### 单源最短路

~~~cpp
void dij(int s) {
	priority_queue <pii, vector<pii>, greater<pii> > q; 
	memset(dis, 0x7f7f7f7f, sizeof(dis));
	q.push({0, s});
	dis[s] = 0;
	while (!q.empty()) {
		pii u = q.top(); q.pop();
		int pos = u.second;
		if (vis[pos]) continue;
		vis[pos] = 1;
		for (int j = last[pos]; j; j = e[j].next) {
			int v = e[j].to;
			if (vis[v]) continue;
			if (dis[pos] + e[j].w < dis[v]) dis[v] = dis[pos] + e[j].w, q.push({dis[v], v});
		}
	}
}
~~~

### 缩点

~~~cpp
int dfn[N], low[N], dcnt, p[N], sum[N];
bool instack[N];
stack <int> s;
void dfs(int x) {
	dfn[x] = low[x] = ++dcnt;
	instack[x] = 1; s.push(x);
	for (int i = oldg.last[x]; i; i = oldg.e[i].next) {
		int v = oldg.e[i].to;
		if (dfn[v]) {
			if (instack[v]) low[x] = min(low[x], dfn[v]);
			continue;
		}
		dfs(v);
		low[x] = min(low[x], low[v]);
	}
	if (low[x] >= dfn[x]) {
		p[x] = x, sum[x] = a[x];
		instack[x] = 0;
		while (s.top() != x) {
			int v = s.top(); s.pop();
			instack[v] = 0;
			p[v] = x, sum[x] += a[v];
		}
		s.pop();
	}
}

for (int i = 1; i <= m; i++) u[i] = read(), v[i] = read();
for (int i = 1; i <= m; i++) oldg.addedge(u[i], v[i]);
for (int i = 1; i <= n; i++)
	if (!dfn[i]) dfs(i);
for (int i = 1; i <= m; i++) 
	if (p[u[i]] != p[v[i]]) newg.addedge(p[u[i]], p[v[i]]);
~~~

### 点双连通分量

~~~cpp
int dfn[N], low[N], tcnt;
vector <int> ans[N]; int anscnt;
stack <int> s;
void dfs(int x, int fa) {
	dfn[x] = low[x] = ++tcnt;
	if (x == fa && !last[x]) {
		ans[++anscnt].emplace_back(x);
		return ; 
	}
	s.push(x);
	for (int i = last[x]; i; i = e[i].next) {
		int v = e[i].to;
		if (dfn[v]) {low[x] = min(low[x], dfn[v]); continue;}
		dfs(v, x);
		low[x] = min(low[x], low[v]);
		if (low[v] >= dfn[x]) {
			anscnt++;
			int now;
			do {
				now = s.top(); s.pop();
				ans[anscnt].emplace_back(now);
			} while (now != v);
			ans[anscnt].emplace_back(x); 
		}
	}
}
~~~

### 边双连通分量

~~~cpp
int low[N << 1], dfn[N << 1], tcnt;
vector <int> ans[N]; int anscnt;
stack <int> s;
void dfs(int x, int edg) {
	dfn[x] = low[x] = ++tcnt;
	s.push(x);
	for (int i = last[x]; i; i = e[i].next) {
		int v = e[i].to;
		if (dfn[v]) {if (i != (edg ^ 1)) low[x] = min(low[x], dfn[v]); continue;}
		dfs(v, i);
		low[x] = min(low[x], low[v]);
		if (low[v] > dfn[x]) {
			anscnt++;
			int now;
			do {
				now = s.top(); s.pop();
				ans[anscnt].emplace_back(now);
			} while (now != v);
		}
	}
}
~~~

### 欧拉路径

~~~cpp
int st[N], ed[N];
struct edge {
	int u, v;
} e[N << 1];
int rd[N], cd[N];
bool cmp(edge x, edge y) {
	if (x.u != y.u) return x.u < y.u;
	return x.v < y.v;
}
int ans[N << 1], cnt;
void dfs(int x) {
	while (st[x] <= ed[x]) {
		st[x]++;
		dfs(e[st[x] - 1].v);
	}
	ans[++cnt] = x;
}
~~~

### 网络最大流

~~~cpp
int dep[N], cur[N];
queue <int> q;
bool bfs() {
	while (q.size()) q.pop();
	for (int i = 1; i <= n; i++) dep[i] = -1; dep[s] = 0;
	cur[s] = last[s]; q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = last[x]; i; i = e[i].next) {
			int v = e[i].to;
			if (dep[v] != -1) continue;
			if (e[i].w == 0) continue;
			dep[v] = dep[x] + 1;
			cur[v] = last[v];
			if (v == t) return 1;
			q.push(v);
		}
	}
	return 0;
}
ll dfs(int x, ll tp) {
	if (x == t) return tp;
	ll res = 0;
	for (int i = cur[x]; i && res < tp; i = e[i].next) {
		cur[x] = i;
		int v = e[i].to;
		if (dep[v] != dep[x] + 1) continue;
		if (e[i].w == 0) continue;
		ll now = dfs(v, min(e[i].w, tp - res));
		if (now == 0) dep[v] = -1;
		e[i].w -= now, e[i ^ 1].w += now, res += now;
	}
	return res;
}
ll dinic() {
	ll res = 0, now;
	while (bfs()) 
		while (now = dfs(s, INF)) res += now;
	return res; 
}
~~~

### 乘法逆元

~~~cpp
fac[0] = fac[1] = 1;
for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
inv[1] = 1;
for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
~~~

### 快速幂

~~~cpp
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
~~~

### 矩阵快速幂

~~~cpp
struct Martix {
	int n, m;
	ll a[N][N];
	void clear() {memset(a, 0, sizeof(a));}
	void init() {clear(); for (int i = 1; i <= n; i++) a[i][i] = 1;}
	Martix operator *(const Martix b) const {
		Martix res; res.clear(); res.n = n, res.m = b.m;
		for (int i = 1; i <= res.n; i++)
			for (int j = 1; j <= res.m; j++)
				for (int k = 1; k <= m; k++)
					res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j] % mod) % mod;
		return res;
	}
	Martix operator ^(ll x) const {
		Martix res, a = *this; res.n = res.m = n, res.init(); 
		while (x) {
			if (x & 1) res = res * a;
			a = a * a;
			x >>= 1;
		} 
		return res;
	}
} a;
~~~

### 线性基

~~~cpp
int p[N];
void add(ll x) {
	for (int i = N; i >= 0; i--) {
		if (!(x & (1ll << i))) continue;
		if (p[i]) x ^= p[i];
		else {p[i] = x; return ;}
	}
}
~~~

### 线性筛

~~~cpp
int prime[6000010], cnt;
bool isprime[N + 10];
void prim() {
	isprime[0] = isprime[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			isprime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
~~~

### 字符串哈希

~~~cpp
int Char(char c) {
	if (c >= '0' && c <= '9') return c - '0' + 1; //0~9: 1~10
	if (c >= 'a' && c <= 'z') return c - 'a' + 11; //a~z: 11~37
	if (c >= 'A' && c <= 'Z') return c - 'A' + 38; //A~Z: 38~65
	return 0;
}
map <ll, int> mp;

cin >> s;
ll x = 0;
for (int i = 0; i < s.size(); i++) x = (x * 100) + Char(s[i]);
mp[x] = 1;
~~~

### KMP

~~~cpp
// s 和 t 为需要匹配的两个 char 类型数组。
// border[i] 表示 t 长度为 i 的前缀最长的 border 长度。
ls = strlen(s + 1), lt = strlen(t + 1);
int j = 0;
for (int i = 2; i <= lt; i++) {
	while (j >= 1 && t[j + 1] != t[i]) j = border[j];
	if (t[j + 1] == t[i]) j++;
	border[i] = j;
}
int sx = 1, tx = 0;
while (sx <= ls) {
	while (tx >= 1 && s[sx] != t[tx + 1]) tx = border[tx];
	if (t[tx + 1] == s[sx]) tx++;
	if (tx == lt) printf("%d\n", sx - lt + 1);
	sx++;
}
~~~

### AC自动机

~~~cpp
struct Trie {
	int id[27], cnt, fail;
} t[N];
void Build(string &s) {
	int now = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!t[now].id[s[i] - 'a']) t[now].id[s[i] - 'a'] = ++cnt;
		now = t[now].id[s[i] - 'a'];
	}
	t[now].cnt++;
}
void Fail() {
	queue <int> q;
	for (int i = 0; i < 26; i++) {
		int v = t[0].id[i];
		if (v != 0) {
			t[v].fail = 0;
			q.push(v);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			int v = t[u].id[i];
			if (v != 0) {
				t[v].fail = t[t[u].fail].id[i];
				q.push(v);
			}
			else t[u].id[i] = t[t[u].fail].id[i];
		}
	}
}
string s;
int ans;
void Query() {
	int now = 0;
	for (int i = 0; i < s.size(); i++) {
		now = t[now].id[s[i] - 'a'];
		for (int to = now; to; to = t[to].fail) {
			if (t[to].cnt == -1) break;
			ans += t[to].cnt;
			t[to].cnt = -1;
		}
	}
}
~~~

### 字符串哈希

~~~cpp
int Char(char c) {
	if (c >= '0' && c <= '9') return c - '0' + 1; //0~9: 1~10
	if (c >= 'a' && c <= 'z') return c - 'a' + 11; //a~z: 11~37
	if (c >= 'A' && c <= 'Z') return c - 'A' + 38; //A~Z: 38~65
	return 0;
}
map <ll, int> mp;

cin >> s;
ll x = 0;
for (int i = 0; i < s.size(); i++) x = (x * 100) + Char(s[i]);
mp[x] = 1;
~~~





~~~cpp
/*
    |埃式筛法|
    |快速筛选素数|
    |16/11/05ztx|
*/

int prime[maxn];  
bool is_prime[maxn];

int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i){   //  注意数组大小是n
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = i + i; j <= n; j += i)  //  轻剪枝，j必定是i的倍数
                is_prime[j] = false;
        }
    }
    return p;   //  返回素数个数
}

/*
    |大数模拟阶乘|
    |用数组模拟|
    |16/12/02ztx|
*/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int maxn = 100010;

int num[maxn], len;

/*
    在mult函数中，形参部分：len每次调用函数都会发生改变，n表示每次要乘以的数，最终返回的是结果的长度
    tip: 阶乘都是先求之前的(n-1)!来求n!
    初始化Init函数很重要，不要落下
*/

void Init() {
    len = 1;
    num[0] = 1;
}

int mult(int num[], int len, int n) {
    LL tmp = 0;
    for(LL i = 0; i < len; ++i) {
         tmp = tmp + num[i] * n;    //从最低位开始，等号左边的tmp表示当前位，右边的tmp表示进位（之前进的位）
         num[i] = tmp % 10; //  保存在对应的数组位置，即去掉进位后的一位数
         tmp = tmp / 10;    //  取整用于再次循环,与n和下一个位置的乘积相加
    }
    while(tmp) {    //  之后的进位处理
         num[len++] = tmp % 10;
         tmp = tmp / 10;
    }
    return len;
}

int main() {
    Init();
    int n;
    n = 1977; // 求的阶乘数
    for(int i = 2; i <= n; ++i) {
        len = mult(num, len, i);
    }
    for(int i = len - 1; i >= 0; --i)
        printf("%d",num[i]);    //  从最高位依次输出,数据比较多采用printf输出
    printf("\n");
    return 0;
}

/*
    |辗转相除法|
    |欧几里得算法|
    |求最大公约数|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}

/*
    |辗转相除法|
    |欧几里得算法|
    |求最小公倍数|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}

/*
    |求1到n的全排列, 有条件|
    |16/11/05ztx, thanks to wangqiqi|
*/

void Pern(int list[], int k, int n) {   //  k表示前k个数不动仅移动后面n-k位数
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        printf("\n");
    }else {
        for (int i = k; i < n; i++) {   //  输出的是满足移动条件所有全排列
            swap(list[k], list[i]);
            Pern(list, k + 1, n);
            swap(list[k], list[i]);
        }
    }
}

/*
    |二分搜索|
    |要求：先排序|
    |16/11/05ztx, thanks to wangxiaocai|
*/

//  left为最开始元素, right是末尾元素的下一个数，x是要找的数
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;    
        // 如果要替换为 upper_bound, 改为:if (A[m] <= v) x = m+1; else y = m;     
    }
    return left;
}

/*
    最后left == right  

    如果没有找到135577找6，返回7  

    如果找有多少的x，可以用lower_bound查找一遍，upper_bound查找一遍，下标相减  

    C++自带的lower_bound(a,a+n,x)返回数组中最后一个x的下一个数的地址 

    upper_bound(a,a+n,x)返回数组中第一个x的地址

    如果a+n内没有找到x或x的下一个地址，返回a+n的地址  

    lower_bound(a,a+n,x）-upper_bound(a,a+n,x)返回数组中x的个数
*/ 

/*
    |合并节点操作|
    |16/11/05ztx, thanks to chaixiaojun|
*/

int father[maxn];   //  储存i的father父节点  

void makeSet() {  
    for (int i = 0; i < maxn; i++)   
        father[i] = i;  
}  

int findRoot(int x) {   //  迭代找根节点
    int root = x; // 根节点  
    while (root != father[root]) { // 寻找根节点  
        root = father[root];  
    }  
    while (x != root) {  
        int tmp = father[x];  
        father[x] = root; // 根节点赋值  
        x = tmp;  
    }  
    return root;  
}  

void Union(int x, int y) {  //  将x所在的集合和y所在的集合整合起来形成一个集合。  
    int a, b;  
    a = findRoot(x);  
    b = findRoot(y);  
    father[a] = b;  // y连在x的根节点上   或father[b] = a为x连在y的根节点上；  
}  

/*
    在findRoot(x)中：
    路径压缩 迭代 最优版
    关键在于在路径上的每个节点都可以直接连接到根上
*/

/*
    |Kruskal算法|
    |适用于 稀疏图 求最小生成树|
    |16/11/05ztx thanks to wangqiqi|
*/

/*
    第一步：点、边、加入vector，把所有边按从小到大排序
    第二步：并查集部分 + 下面的code
*/

void Kruskal() {    
    ans = 0;    
    for (int i = 0; i<len; i++) {    
        if (Find(edge[i].a) != Find(edge[i].b)) {    
            Union(edge[i].a, edge[i].b);    
            ans += edge[i].len;    
        }    
    }    
}    

/*
    |Prim算法|
    |适用于 稠密图 求最小生成树|
    |堆优化版，时间复杂度：O(elgn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {  
    int v, len;  
    node(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator < (const node &a)const {  // 加入队列的元素自动按距离从小到大排序  
        return len> a.len;  
    }  
};

vector<node> G[maxn];
int vis[maxn];
int dis[maxn];

void init() {  
    for (int i = 0; i<maxn; i++) {  
        G[i].clear();  
        dis[i] = INF;  
        vis[i] = false;  
    }  
}  
int Prim(int s) {  
    priority_queue<node>Q; // 定义优先队列  
    int ans = 0;  
    Q.push(node(s,0));  // 起点加入队列  
    while (!Q.empty()) {   
        node now = Q.top(); Q.pop();  // 取出距离最小的点  
        int v = now.v;  
        if (vis[v]) continue;  // 同一个节点，可能会推入2次或2次以上队列，这样第一个被标记后，剩下的需要直接跳过。  
        vis[v] = true;  // 标记一下  
        ans += now.len;  
        for (int i = 0; i<G[v].size(); i++) {  // 开始更新  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;  
            if (!vis[v2] && dis[v2] > len) {   
                dis[v2] = len;  
                Q.push(node(v2, dis[v2]));  // 更新的点加入队列并排序  
            }  
        }  
    }  
    return ans; 
}  

/*
    |Dijkstra算法|
    |适用于边权为正的有向图或者无向图|
    |求从单个源点出发，到所有节点的最短路|
    |优化版：时间复杂度 O(elbn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {  
    int v, len;  
    node(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator < (const node &a)const {  //  距离从小到大排序  
        return len > a.len;  
    }  
};  

vector<node>G[maxn];  
bool vis[maxn];  
int dis[maxn];

void init() {  
    for (int i = 0; i<maxn; i++) {  
        G[i].clear();  
        vis[i] = false;  
        dis[i] = INF;  
    }  
}  
int dijkstra(int s, int e) {  
    priority_queue<node>Q;  
    Q.push(node(s, 0)); //  加入队列并排序  
    dis[s] = 0;  
    while (!Q.empty()) {  
        node now = Q.top();     //  取出当前最小的  
        Q.pop();  
        int v = now.v;  
        if (vis[v]) continue;   //  如果标记过了, 直接continue  
        vis[v] = true;  
        for (int i = 0; i<G[v].size(); i++) {   //  更新  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;  
            if (!vis[v2] && dis[v2] > dis[v] + len) {  
                dis[v2] = dis[v] + len;  
                Q.push(node(v2, dis[v2]));  
            }  
        }  
    }  
    return dis[e];  
}  

/*
    |SPFA算法|
    |队列优化|
    |可处理负环|
*/

vector<node> G[maxn];
bool inqueue[maxn];
int dist[maxn];

void Init()  
{  
    for(int i = 0 ; i < maxn ; ++i){  
        G[i].clear();  
        dist[i] = INF;  
    }  
}  
int SPFA(int s,int e)  
{  
    int v1,v2,weight;  
    queue<int> Q;  
    memset(inqueue,false,sizeof(inqueue)); // 标记是否在队列中  
    memset(cnt,0,sizeof(cnt)); // 加入队列的次数  
    dist[s] = 0;  
    Q.push(s); // 起点加入队列  
    inqueue[s] = true; // 标记  
    while(!Q.empty()){  
        v1 = Q.front();  
        Q.pop();  
        inqueue[v1] = false; // 取消标记  
        for(int i = 0 ; i < G[v1].size() ; ++i){ // 搜索v1的链表  
            v2 = G[v1][i].vex;  
            weight = G[v1][i].weight;  
            if(dist[v2] > dist[v1] + weight){ // 松弛操作  
                dist[v2] = dist[v1] + weight;  
                if(inqueue[v2] == false){  // 再次加入队列  
                    inqueue[v2] = true;  
                    //cnt[v2]++;  // 判负环  
                    //if(cnt[v2] > n) return -1;  
                    Q.push(v2);  
                } } }  
    }  
    return dist[e];  
}

/*
    不断的将s的邻接点加入队列，取出不断的进行松弛操作，直到队列为空  

    如果一个结点被加入队列超过n-1次，那么显然图中有负环  
*/

/*
    |Floyd算法|
    |任意点对最短路算法|
    |求图中任意两点的最短距离的算法|
*/

for (int i = 0; i < n; i++) {   //  初始化为0  
    for (int j = 0; j < n; j++)  
        scanf("%lf", &dis[i][j]);  
}  
for (int k = 0; k < n; k++) {  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);  
        }  
    }
}

/*
    |交叉染色法判断二分图|
    |16/11/05ztx|
*/

int bipartite(int s) {  
    int u, v;  
    queue<int>Q;  
    color[s] = 1;  
    Q.push(s);  
    while (!Q.empty()) {  
        u = Q.front();  
        Q.pop();  
        for (int i = 0; i < G[u].size(); i++) {  
            v = G[u][i];  
            if (color[v] == 0) {  
                color[v] = -color[u];  
                Q.push(v);  
            }  
            else if (color[v] == color[u])  
                return 0;  
        }  
    }  
    return 1;  
}  

/*
    |求解最大匹配问题|
    |dfs实现|
    |16/11/05ztx|
*/

int v1, v2;  
bool Map[501][501];  
bool visit[501];  
int link[501];  
int result;  

bool dfs(int x)  {  
    for (int y = 1; y <= v2; ++y)  {  
        if (Map[x][y] && !visit[y])  {  
            visit[y] = true;  
            if (link[y] == 0 || dfs(link[y]))  {  
                link[y] = x;  
                return true;  
            } } }  
    return false;  
}  


void Search()  {  
    for (int x = 1; x <= v1; x++)  {  
        memset(visit,false,sizeof(visit));  
        if (dfs(x))  
            result++;  
    }
}

/*
    |求解最大匹配问题|
    |递归实现|
    |16/11/05ztx|
*/

vector<int>G[maxn];  
bool inpath[maxn];  //  标记  
int match[maxn];    //  记录匹配对象  
void init()  
{  
    memset(match, -1, sizeof(match));  
    for (int i = 0; i < maxn; ++i) {  
        G[i].clear();  
    }  
}  
bool findpath(int k) {  
    for (int i = 0; i < G[k].size(); ++i) {  
        int v = G[k][i];  
        if (!inpath[v]) {  
            inpath[v] = true;  
            if (match[v] == -1 || findpath(match[v])) { // 递归  
                match[v] = k; // 即匹配对象是“k妹子”的  
                return true;  
            }  
        }  
    }  
    return false;  
}  

void hungary() {  
    int cnt = 0;  
    for (int i = 1; i <= m; i++) {  // m为需要匹配的“妹子”数  
        memset(inpath, false, sizeof(inpath)); // 每次都要初始化  
        if (findpath(i)) cnt++;  
    }  
    cout << cnt << endl;  
}  

/*
    |01背包|
    |完全背包|
    |多重背包|
    |16/11/05ztx|
*/

//  01背包：  

void bag01(int cost,int weight)  {  
    for(i = v; i >= cost; --i)  
    dp[i] = max(dp[i], dp[i-cost]+weight);  
}  

//  完全背包：  

void complete(int cost, int weight)  {  
    for(i = cost ; i <= v; ++i)  
    dp[i] = max(dp[i], dp[i - cost] + weight);  
}  

//  多重背包：  

void multiply(int cost, int weight, int amount)  {  
    if(cost * amount >= v)  
        complete(cost, weight);  
    else{  
        k = 1;  
        while (k < amount){  
            bag01(k * cost, k * weight);  
            amount -= k;  
            k += k;  
        }  
        bag01(cost * amount, weight * amount);  
    }  
}  


// other

int dp[1000000];
int c[55], m[110];
int sum;

void CompletePack(int c) {
    for (int v = c; v <= sum / 2; ++v){
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void ZeroOnePack(int c) {
    for (int v = sum / 2; v >= c; --v) {
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void multiplePack(int c, int m） {
    if (m * c > sum / 2)
        CompletePack(c);
    else{
        int k = 1;
        while (k < m){
            ZeroOnePack(k * c);
            m -= k;
            k <<= 1;
        }
        if (m != 0){
            ZeroOnePack(m * c);
        }
    }
}

/*
    |最长上升子序列|
    |状态转移|
    |16/11/05ztx|
*/

/*
    状态转移dp[i] = max{ 1.dp[j] + 1 };  j<i; a[j]<a[i];
    d[i]是以i结尾的最长上升子序列
    与i之前的 每个a[j]<a[i]的 j的位置的最长上升子序列+1后的值比较
*/

void solve(){   // 参考挑战程序设计入门经典;
    for(int i = 0; i < n; ++i){  
        dp[i] = 1;  
        for(int j = 0; j < i; ++j){  
            if(a[j] < a[i]){  
                dp[i] = max(dp[i], dp[j] + 1);  
            } } }
}  

/* 
    优化方法：
    dp[i]表示长度为i+1的上升子序列的最末尾元素  
    找到第一个比dp末尾大的来代替 
*/

    void solve() {  
        for (int i = 0; i < n; ++i){
            dp[i] = INF;
        }
        for (int i = 0; i < n; ++i) {  
            *lower_bound(dp, dp + n, a[i]) = a[i];  //  返回一个指针  
        }  
        printf("%d\n", *lower_bound(dp, dp + n, INF) - dp;  
    }

/*  
    函数lower_bound()返回一个 iterator 它指向在[first,last)标记的有序序列中可以插入value，而不会破坏容器顺序的第一个位置，而这个位置标记了一个不小于value的值。
*/
               
/*
    |求最长公共子序列|
    |递推形式|
    |16/11/05ztx|
*/

void solve() {  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            if (s1[i] == s2[j]) {  
                dp[i + 1][j + 1] = dp[i][j] + 1;  
            }else {  
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);  
            } } }
}  

/*
    |16/11/06ztx|
*/

struct node {  
    double x; // 横坐标  
    double y; // 纵坐标  
};  

typedef node Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }  
Vector operator - (Point A, Point B) { return Vector(A.x - B.y, A.y - B.y); }  
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }  
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y*p); }  

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; } // 向量点乘  
double Length(Vector A) { return sqrt(Dot(A, A)); }  // 向量模长  
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }  // 向量之间夹角  

double Cross(Vector A, Vector B) { // 叉积计算 公式  
    return A.x*B.y - A.y*B.x;  
}  

Vector Rotate(Vector A, double rad) // 向量旋转 公式  {  
    return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));  
}  

Point getLineIntersection(Point P, Vector v, Point Q, Vector w) { // 两直线交点t1 t2计算公式   
    Vector u = P - Q;   
    double t = Cross(w, u) / Cross(v, w);  // 求得是横坐标  
    return P + v*t;  // 返回一个点  
}  
/*
    |16/11/06ztx|
*/

node G[maxn];  
int n;  

double Cross(node a, node b) { // 叉积计算  
    return a.x*b.y - a.y*b.x;  
}  


int main()  
{  
    while (scanf("%d", &n) != EOF && n) {  
        for (int i = 0; i < n; i++)   
            scanf("%lf %lf", &G[i].x, &G[i].y);  
        double sum = 0;  
        G[n].x = G[0].x;  
        G[n].y = G[0].y;  
        for (int i = 0; i < n; i++) {   
                sum += Cross(G[i], G[i + 1]);  
        }  
        // 或者  
            //for (int i = 0; i < n; i++) {  
                //sum += fun(G[i], G[（i + 1）% n]);  
            //}  
        sum = sum / 2.0;  
        printf("%.1f\n", sum);  
    }  
    system("pause");  
    return 0;  
}
/*
    |16/11/06ztx|
*/

node P[35][105];     

double Cross_Prouct(node A,node B,node C) {     //  计算BA叉乘CA     
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);      
}      
bool Intersect(node A,node B,node C,node D)  {  //  通过叉乘判断线段是否相交；           
    if(min(A.x,B.x)<=max(C.x,D.x)&&         //  快速排斥实验；      
       min(C.x,D.x)<=max(A.x,B.x)&&      
       min(A.y,B.y)<=max(C.y,D.y)&&      
       min(C.y,D.y)<=max(A.y,B.y)&&      
       Cross_Prouct(A,B,C)*Cross_Prouct(A,B,D)<0&&      //  跨立实验；      
       Cross_Prouct(C,D,A)*Cross_Prouct(C,D,B)<0)       //  叉乘异号表示在两侧；      
       return true;      
    else return false;      
}    
/*
    |16/11/06ztx|
    中国剩余定理
*/

int CRT(int a[],int m[],int n)  {    
    int M = 1;    
    int ans = 0;    
    for(int i=1; i<=n; i++)    
        M *= m[i];    
    for(int i=1; i<=n; i++)  {    
        int x, y;    
        int Mi = M / m[i];    
        extend_Euclid(Mi, m[i], x, y);    
        ans = (ans + Mi * x * a[i]) % M;    
    }    
    if(ans < 0) ans += M;    
    return ans;    
}  

void extend_Euclid(int a, int b, int &x, int &y)  {  
    if(b == 0) {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a % b, x, y);  
    int tmp = x;  
    x = y;  
    y = tmp - (a / b) * y;  
}  
~~~