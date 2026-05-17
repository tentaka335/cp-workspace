#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> G(200009);
vector<bool> visited(200009);
set<pair<ll,ll>> visitededge;
ll ans = 0;
ll nowedge = 0;
ll nownord = 0;


void dfs(ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(!visitededge.count({pos,nex}) && !visitededge.count({nex,pos})) {
            nowedge++;
            visitededge.insert(make_pair(pos,nex));
        }
        if(visited[nex]==false) {
            nownord++;
            dfs(nex);
        }
    }
}

    

int main () {
    ll n,m;
    cin >> n >> m;
    
    for(ll i = 0;i<m;i++) {
        ll u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(ll i = 1;i<=n;i++) {
        if(visited[i] == false) {
            nownord++;
            dfs(i);
            ans +=nowedge-(nownord-1);
            nowedge = 0;
            nownord = 0;
        }
    }
    cout << ans << "\n";
}

//もう少し考察すれば連結部分の個数を求めるだけで済んだ。
//一応連結部分の辺の数、辺の個数をカウントすることはできたからよかった。

