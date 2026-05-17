#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> edges(m);

    for (ll i=0; i<m; i++) {
        ll u,v;
        cin >> u >> v;
        edges[i].first = u-1;
        edges[i].second = v-1;
    }
    ll ans = m;
    for(ll bit=0; bit< 1<<n; bit++) {
        ll deletecount = 0;
        for (ll i = 0; i<m; i++) {
            if ((1 & (bit >> edges[i].first)) == (1 & (bit >> edges[i].second))) deletecount ++;
        }
        ans = min(ans, deletecount);
    }
    cout << ans << endl;
}