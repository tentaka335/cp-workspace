#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,m;
vector<vector<ll>> G(200009);
vector<ll> visited(200009,false);
bool ok = true;
void dfs (ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex] == false) dfs(nex);
    }
    return ;
} 

int main () {
    cin >> n >> m;
    for(ll i = 0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(ll i =1;i<=n;i++) {
        if(G[i].size() != 2) ok = false;
    }

    dfs(1);
    for(ll i = 1;i<=n;i++) {
        if (visited[i] == false) ok = false;
    }

    cout << (ok?"Yes":"No") << "\n";
}