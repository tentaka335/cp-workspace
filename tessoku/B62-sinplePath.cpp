#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> beforevisited(100009);
vector<bool> visited(100009);
vector<vector<ll>> G(100009);

void dfs(ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i] ;
        if(visited[nex]==false) {
            beforevisited[nex] = pos;
            dfs(nex); 
        }
    }
}


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    for(ll i = 1;i<=m;i++) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    ll pos = n;
    vector<ll> ans;
    ans.push_back(n);
    while(pos!=1) {
        pos = beforevisited[pos];
        ans.push_back(pos);
    }
    reverse(ans.begin(),ans.end());
    for(ll i =0;i<ans.size();i++) cout << ans[i] << " ";
}