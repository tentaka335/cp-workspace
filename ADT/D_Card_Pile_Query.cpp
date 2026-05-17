#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll n,q;
vector<vector<ll>> G(300009);
vector<bool> istop(300009,true);
vector<ll> ans(300009,0);

void dfs(ll pos,ll sonnum) {
    
    if(G[pos].size()==0) {
        ans[pos] = sonnum+1;
    }
    else {
        dfs(G[pos][0],sonnum+1);
    }
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> q;
    
    rep(qi,q) {
        ll c,p;
        cin >> c >> p;
        if(G[c].size()==0) {
            G[c].push_back(p);
            istop[p] = false;
        }
        else {
            istop[G[c][0]] = true;
            G[c].pop_back();
            G[c].push_back(p);
            istop[p] = false;
        }
    }
    for(ll i = 1;i<=n;i++) {
        if(istop[i] == true) {
            dfs(i,0);
        }
    }
    for(ll i = 1;i<=n;i++) cout << ans[i] <<" ";
    return 0;
}