#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
    public:
    ll par[100009];
    ll siz[100009];

    //N頂点のUnionFindを作成
    void init(ll N) {
        for(ll i = 1;i<=N;i++) par[i] = -1;
        for(ll i = 1;i<=N;i++) siz[i] = 1;
    }
    //x頂点の根を返す関数
    ll root(ll x) {
        while(true) {
            if(par[x] == -1) break;
            x = par[x];
        }
        return x;
    }
    void unite(ll u,ll v) {
        ll RootU = root(u);
        ll RootV = root(v);
        if(RootU == RootV) return;
        if(siz[RootU] < siz[RootV]) {//Union by size
            par[RootU] = RootV;
            siz[RootV] = siz[RootU] + siz[RootV];
        }
        else {
            par[RootV] = RootU;
            siz[RootU] = siz[RootU] + siz[RootV];
        }
    }
    bool same(ll u,ll v) {
        if(root(u)==root(v)) return true;
        else return false;
    }
};

int main () {
    ll ans = 0;
    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edge;
    for(ll i = 1;i<=m;i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        edge.emplace_back(c,a,b);
    }
    sort(edge.rbegin(),edge.rend());
    UnionFind UF;
    UF.init(n);
    for(ll i = 0;i<m;i++) {
        auto [c,a,b] = edge[i];
        if(!UF.same(a,b)) {
            UF.unite(a,b);
            ans +=c;
        }
    }
    cout << ans << "\n";
}

//最小の辺から順につなげていく。もしその辺をつなげたとしても、木の頂点数が増えないなら、つなげずにスキップ
//クラスカル法
//tupleはget<i>(uple)で各要素にアクセスできる。
