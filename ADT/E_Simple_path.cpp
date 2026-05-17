#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;


vector<vector<ll>> G(200009);
vector<bool> visited(200009);
vector<ll> before(200009);
void dfs (ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nx = G[pos][i];
        if(visited[nx] == false ) {
            before[nx] = pos;
            dfs(nx);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,x,y;
    cin >> n >> x >> y;

    rep(i,n-1) {
        ll u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(x);
    
    vector<ll> ans;
    ans.push_back(y);
    ll pos = y;
    while(pos!=x) {
        pos = before[pos];
        ans.push_back(pos);
    }
    reverse(all(ans));
    rep(i,ans.size()) cout << ans[i] <<  " "; 
    return 0;
}