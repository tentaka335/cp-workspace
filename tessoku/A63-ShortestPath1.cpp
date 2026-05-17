#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> G(n+1);
    vector<ll> minp(n+1,m+1);
    minp[1] = 0;
    for(ll i = 0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);//pairにする。
        G[b].push_back(a);
    }
    queue<ll> next;//pairでいける。
    vector<bool> visited(n+1,false);//二次元配列でいく。
     next.push(1);//pair1,1
     visited[1] = true;
     while(next.size() != 0) {
        ll pos = next.front();
        next.pop();
        for(ll i = 0;i<G[pos].size();i++) {
            minp[G[pos][i]] = min(minp[pos]+1,minp[G[pos][i]]);
            if(visited[G[pos][i]] == false ) {
                visited[G[pos][i]] = true;
                next.push(G[pos][i]);
            }
        }
     }
     for(ll i =1;i<=n;i++) {
        if(minp[i] == m+1) cout << -1 << "\n";
        else cout << minp[i] << "\n";
     }
}