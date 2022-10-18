//Submitted to: https://judge.yosupo.jp/problem/unionfind
#include <bits/stdc++.h>
using namespace std;

/* Macros */
#define reu(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define deb(x) {if (DEBUG) {cout << #x << ": " << x << '\n';}}
#define deb2(x, y) {if (DEBUG) {cout << #x << ": " << x << ' ' << #y << ": " << y << '\n';}}
#define pb push_back
#define mp make_pair
#define BIT(s, i) (((s)>>(i))&1)
#define MASK(s) (1ll<<(s))

/* Variables type shortname */
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

/* Regularly used functions */
template<class T> 
bool maximize(T &a, T b) {
	if (a < b) {a = b; return true;}
	return false;
}

template<class T>
bool minimize(T &a, T b) {
	if (a > b) {a = b; return true;}
	return false;
}

/* Main solution */
#define DEBUG 1 //set to 1 when in need to use deb(x) or deb2(x, y) or for other debug operations, should set to 0 when submit. 
int n, q;

struct DSU {
	vi par, siz;
	int n;

	DSU(int n) {
		this->n = n;
		par.assign(n+1, 0);
		reu(i, 0, n) par[i] = i;
		siz.assign(n+1, 0);
	}

	int findSet(int u) {
		if (par[u] == u) return u;
		return par[u] = findSet(par[u]);
	}

	bool unite(int u, int v) {
		u = findSet(u);
		v = findSet(v);
		if (u == v) return false;
		if (siz[u] < siz[v]) swap(u, v);
		par[v] = u;
		siz[u] += siz[v];
		return true;
	}
};

void Input() {
	cin >> n >> q;
}

void Solve() {
	DSU dsu(n);
	while (q--) {
		int t, u, v; cin >> t >> u >> v;
		if (t == 0) dsu.unite(u, v);
		else cout << (dsu.findSet(u) == dsu.findSet(v)) << '\n'; 
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t = 1; //cin >> t;
	while (t--)
	Input(), Solve();
	return 0;
}
