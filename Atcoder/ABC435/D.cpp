#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,m,q;
vector<vector<ll>> G(300009);
vector<bool> Bvisited(300009);

void dfs (ll pos) {
    Bvisited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        if(Bvisited[G[pos][i]] == false) dfs(G[pos][i]);
    }
    return ;
}


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(ll i = 0;i<m;i++) {
        ll x,y;
        cin >> x >> y;
        G[y].push_back(x);
    }
    cin >> q;
    for(ll i = 0;i<q;i++) {
        ll qt,v;
        cin >> qt >> v;
        if(qt == 1 && Bvisited[v] == false) dfs(v);
        else if(qt == 2) {
            if(Bvisited[v] == false) cout << "No" << "\n";
            else cout << "Yes" << "\n";
        }
    }
}