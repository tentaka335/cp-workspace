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
ll n,q,query[100009],u[100009],v[100009];
int main () {
    cin >> n >> q;
    for(ll i = 0;i<q;i++) cin >> query[i] >> u[i] >> v[i];

    UnionFind UF;
    UF.init(n);
    for(ll i = 0;i<q;i++) {
        if(query[i]==1) {
            UF.unite(u[i],v[i]);
        }
        else {
            cout << (UF.same(u[i],v[i])?"Yes":"No") << "\n";
        }
    }
}

