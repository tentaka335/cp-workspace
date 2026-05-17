#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,m;
vector<vector<ll>> G(1000009);
vector<bool> visited(100009,false);

void dfs (ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if (visited[nex] == false) dfs(nex);
    }
    return ;
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(ll i = 0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for(ll i =1;i<=n;i++) {
        if(visited[i] == false) {
            cout << "The graph is not connected." << "\n";
            return 0;
        }
    }
    cout << "The graph is connected." << "\n";
    return 0;
    }
