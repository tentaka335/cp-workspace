#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

vector<vector<ll>> G(100009);
vector<bool> visited(100009);
vector<bool> invvisited(100009);
vector<vector<ll>> invG(100009);
stack<ll> S;
vector<ll> temp;
ll ans = 0;
void dfs (ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex] == false)  {
            dfs(nex);
        }
    }
    S.push(pos);
}
void dfs2 (ll pos) {
    temp.push_back(pos);
     invvisited[pos] = true;
    for(ll i = 0;i<invG[pos].size();i++) {
        ll nex = invG[pos][i];
        if(invvisited[nex] == false)  {
            dfs2(nex);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        invG[b].push_back(a);
    }
    for(ll i = 1;i<=n;i++) {
        if(visited[i] == false) dfs(i);
    }

    while(!S.empty()) {
        ll pos = S.top();
        S.pop();
        if(invvisited[pos] == false) {
            dfs2(pos);
            ll size = temp.size();
            temp.clear();
            ans+=size*(size-1)/2;
        }
    }
  
    cout << ans;

    
    return 0;
}