#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

//dfs
ll n,m,l,s,t;

vector<vector<Pll>> G(200009);
set<ll> ans;


void dfs(ll pos,ll csum,ll msum) {

    if (msum <l-1) {
        for(ll i = 0;i<G[pos].size();i++) {
            ll nxpos = G[pos][i].first;
            ll nxcost = G[pos][i].second;
            dfs(nxpos,nxcost+csum,msum+1);
    }
}
else if (msum == l-1) {
    for(ll i = 0;i<G[pos].size();i++) {
        ll nxpos = G[pos][i].first;
        ll nxcost = G[pos][i].second;
        if(s<=nxcost+csum&&nxcost+csum<=t) ans.insert(nxpos);
    }
}
}



int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> l >> s >> t;
    for(ll i = 0;i<m;i++) {
        ll u,v,c;
        cin >> u >> v >> c;
        G[u].push_back({v,c});
    }

    dfs(1,0,0);

    for(auto it : ans) {
        cout << it << " ";
    }
    if(ans.size()==0) cout << " ";
}




/*

*/



