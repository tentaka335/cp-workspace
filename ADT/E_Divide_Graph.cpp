#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 998244353 ;

    //a^bのmodm
long long modpow(long long a, long long b, long long m) {
   ll p = a,answer = 1;
   for(ll i = 0;i<30;i++) {
    ll wari = (1<<i);
    if(b/wari%2==1) {
        answer = (answer*p)%m;
    }
    p = (p*p)%m;
   }
   return answer;
}



class UnionFind {
    public:
    ll par[200009];
    ll siz[200009];
    ll renketu;

    //N頂点のUnionFindを作成
    void init(ll N) {
        for(ll i = 1;i<=N;i++) par[i] = -1;
        for(ll i = 1;i<=N;i++) siz[i] = 1;
        renketu = N;
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
        else renketu--;
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,m;
    cin >> n >> m;

    
    vector<bool> used(m+1);
    vector<pair<ll,ll>> Q(m+1);
    

    for(ll i = 1;i<=m;i++) {
        ll u,v;
        cin >> u >> v;
        Q[i]= {u,v};
    }

    UnionFind UF;
    UF.init(n);
    if(UF.renketu==2) {
        cout << 2;
        return 0;
    }
    ll i = m;
    while(true) {
        auto [u,v] = Q[i];
        UF.unite(u,v);
        used[i] = true;
        i--;
        if(UF.renketu==2) {
            break;
        }
        

    }
    while (i>=1) {
        auto [u,v] = Q[i];
        if(UF.root(u)==UF.root(v)) {
            UF.unite(u,v);
            used[i] = true;
        }
        i--;
    }

    ll ans = 0;



cd kyoo
    for(ll j = 1;j<=m;j++) {
        if(used[j]==false) {
            ans = (ans + modpow(2,j,MOD)) % MOD;
        }
    }

    cout << ans;
    
    
    return 0;
}