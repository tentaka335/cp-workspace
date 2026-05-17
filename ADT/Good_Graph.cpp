#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
class UnionFind {
public:
	int par[200009];
	int siz[200009];

	// N 頂点の Union-Find を作成
	void init(int N) {
		for (int i = 1; i <= N; i++) par[i] = -1; // 最初は親が無い
		for (int i = 1; i <= N; i++) siz[i] = 1; // 最初はグループの頂点数が 1
	}

	// 頂点 x の根を返す関数
	int root(int x) {
		while (true) {
			if (par[x] == -1) break; // 1 個先（親）がなければ、ここが根
			x = par[x]; // 1 個先（親）に進む
		}
		return x;
	}

	// 要素 u と v を統合する関数
	void unite(int u, int v) {
		int RootU = root(u);
		int RootV = root(v);
		if (RootU == RootV) return; // u と v が同グループのときは処理を行わない
		if (siz[RootU] < siz[RootV]) {
			par[RootU] = RootV;
			siz[RootV] = siz[RootU] + siz[RootV];
		}
		else {
			par[RootV] = RootU;
			siz[RootU] = siz[RootU] + siz[RootV];
		}
	}

	// 要素 u と v が同一のグループかどうかを返す関数
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    UnionFind UF;
    UF.init(n);
    rep(i,m) {
        ll u,v;
        cin >> u >> v;
        UF.unite(u,v);
    }
    ll k;
    cin >> k;
    set<Pll> dontunite;
    rep(i,k) {
        ll x,y;
        cin >>x >> y;
        ll parx = UF.root(x),pary = UF.root(y);
        x,y;
        dontunite.insert({parx,pary});
    }
    ll q;
    cin >> q;
    rep(qi,q) {
        ll p,q;
        cin >> p >> q;
        ll parp = UF.root(p),parq = UF.root(q);
        if(dontunite.count({parp,parq})||dontunite.count({parq,parp})) {
            cout << "No" << "\n";
        }
        else cout << "Yes" << "\n";
    }
    
    return 0;
}