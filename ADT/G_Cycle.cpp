#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> G(n+1);
    vector<bool> visited(n+1);
    vector<ll> goal;
    vector<ll> dist(n+1,inf);
    rep(i,m) {
        ll a,b;
        cin >> a >> b; 
        if(b!=1) G[a].push_back(b);
        else goal.push_back(a);
    }
    queue<ll> Q;
    Q.push(1);
    visited[1] = true;
    dist[1] = 0;

    while(!Q.empty()) {
        ll pos = Q.front();
        Q.pop();
        for(ll i = 0;i<G[pos].size();i++) {
            ll nx = G[pos][i];
            if(visited[nx] == false) {
                visited[nx] = true;
                dist[nx] = dist[pos] + 1;
                Q.push(nx);
            }
        }
    }
    ll ans = inf;
    for(ll i = 0;i<goal.size();i++) {
        ans = min(ans,dist[goal[i]] + 1);
    } 
    
    if(ans == inf) cout << -1;
    else cout << ans;

    
    return 0;
}