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

map<ll, ll> a;
int q;

void Input() {
	cin >> q;
	while (q--) {
		ll t, k, v; cin >> t >> k;
		if (t == 0) cin >> a[k];
		else cout << a[k] << '\n';
	}	
}

void Solve() {

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t = 1; //cin >> t;
	while (t--)
	Input(), Solve();
	return 0;
}
