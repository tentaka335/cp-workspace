#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n+1);
    for(ll i = 0 ;i<m;i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    //ダイケストラ
    vector<bool> visited1(n+1);
    vector<ll> cur1(n+1,99999999999);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> dai1;

    vector<bool> visitedn(n+1);
    vector<ll> curn(n+1,999999999999);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> dain;

    //1から
    cur1[1] = 0;
    dai1.push({cur1[1],1});
    while(!dai1.empty()) {
        
        ll pos = dai1.top().second;
        dai1.pop();
        if(visited1[pos]==true) continue;
        visited1[pos] = true;
        for(ll i = 0;i<G[pos].size();i++) {
           ll nex = G[pos][i].first;
           ll nexdist = G[pos][i].second;
           if(cur1[nex]>cur1[pos]+nexdist) {
            cur1[nex] = cur1[pos] + nexdist;
            dai1.push(make_pair(cur1[nex],nex));
           }
        }
    }
    //nから
    curn[n] = 0;
    dain.push({curn[n],n});
    while(!dain.empty()) {
        
        ll pos = dain.top().second;
        dain.pop();
        if(visitedn[pos]==true) continue;
        visitedn[pos] = true;
        for(ll i = 0;i<G[pos].size();i++) {
           ll nex = G[pos][i].first;
           ll nexdist = G[pos][i].second;
           if(curn[nex]>curn[pos]+nexdist) {
            curn[nex] = curn[pos] + nexdist;
            dain.push(make_pair(curn[nex],nex));
           }
        }
    }
    for(ll i = 1;i<=n;i++) {
        if(i==1||i==n) cout << cur1[n] << "\n";
        else cout << cur1[i] + curn[i] << "\n";
    }
}