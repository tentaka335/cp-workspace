#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
ll n,m;
cin >> n >> m ;
set<pair<ll,ll>> G;
ll ans = 0;
for(ll i = 0;i<m;i++) {
    ll u,v;
    cin >> u >> v;
    if(u==v) ans++;
    else if(G.count({u,v})||G.count({v,u})) ans++;
    else G.insert(make_pair(u,v));
}
cout << ans << "\n";
}


