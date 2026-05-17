#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
ll n,m;
vector<vector<ll>> G(300009);
vector<bool> visited(300009);

void dfs(ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex] == false) {
            dfs(nex);
        }
    }
    return ;
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    rep(i,m) {
        ll x,y;
        cin >> x >> y;
        G[y].push_back(x);
    }


    ll q;
    cin >> q;
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll v;
            cin >> v;
            if(visited[v] == false) {
                dfs(v);
            }
        }
        else {
            ll v;
            cin >> v;
            cout << (visited[v]?"Yes":"No") << "\n";
        }
    }
    
    return 0;
}