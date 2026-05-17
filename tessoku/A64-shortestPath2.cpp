#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n+1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q;
    vector<bool> fix(n+1);
    vector<ll> cur(n+1,999999999);
    for(ll i = 0;i<m;i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    cur[1] = 0;
    Q.push(make_pair(cur[1],1));

    while(!Q.empty()) {
        ll pos = Q.top().second;
        Q.pop();
        if(fix[pos] == true) continue;
        fix[pos] = true;
        for(ll i = 0;i<G[pos].size();i++) {
            ll nex = G[pos][i].first;
            ll cost = G[pos][i].second;
            if(cur[nex]>cur[pos]+cost) {
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex],nex));//距離の暫定値を更新する。
            }
        }
    }
    for(ll i = 1;i<=n;i++) {
        if(cur[i] == 999999999) cout << -1 << "\n";
        else cout << cur[i] << "\n";
    }
    return 0;
}