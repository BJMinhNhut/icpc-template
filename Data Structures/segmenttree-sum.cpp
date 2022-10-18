//Submitted to: https://judge.yosupo.jp/problem/point_add_range_sum
#include <bits/stdc++.h>
using namespace std;

/* Macros */
#define reu(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define re1u(i, n) for(int i = 0; i < (n); ++i)
#define re1d(i, n) for(int i = (n)-1; i >= 0; --i)
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

template<class T>
class SegTree_Sum {
	int n;
	vector<T> nodes;
	#define mid (((b)+(e))>>1)

	void build(vi &a, int p, int b, int e) {
		if (b == e) nodes[p] = a[b];
		else {
			build(a, p<<1, b, mid);
			build(a, (p<<1)|1, mid+1, e);
			nodes[p] = nodes[p<<1] + nodes[(p<<1)|1];
		}
	}

	void update(int pos, T val, int p, int b, int e) {
		if (pos < b || e < pos || b > e) return;
		if (b == e) nodes[p] += val;
		else {
			if (pos <= mid) update(pos, val, p<<1, b, mid);
			else update(pos, val, (p<<1)|1, mid+1, e);
			nodes[p] = nodes[p<<1] + nodes[(p<<1)|1];
		}
	}	

	T getSum(int L, int R, int p, int b, int e) {
		if (R < b || e < L || L > R) return 0;
		if (L <= b && e <= R) return nodes[p];
		return getSum(L, R, p<<1, b, mid) + getSum(L, R, (p<<1)|1, mid+1, e); 
	}

public:

	SegTree_Sum(int n) {
		this->n = n;
		nodes.assign(4*n+4, 0);
	}

	void build(vi &a) {
		build(a, 1, 0, n-1);
	}

	void update(int pos, int val) {
		update(pos, val, 1, 0, n-1);
	}

	T getSum(int L, int R) {
		return getSum(L, R, 1, 0, n-1);
	}
};

int n, q;
vi a;

void Input() {
	cin >> n >> q;
	a.assign(n, 0);
	reu(i, 0, n-1) cin >> a[i];
}

void Solve() {
	SegTree_Sum<ll> ST(n);
	ST.build(a);
	while (q--) {
		int t; cin >> t;
		if (t == 0) {
			int p, x; cin >> p >> x;
			ST.update(p, x);
		} else {
			int L, R; cin >> L >> R;
			cout << ST.getSum(L, R-1) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t = 1; //cin >> t;
	while (t--)
	Input(), Solve();
	return 0;
}
