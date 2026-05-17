#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,m;
    cin >> n >> m;
    map<ll,ll> nodesum;
    for(ll i = 0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        ll k = (a + b)%n;
        nodesum[k] +=1;
    }
    ll ans = (m*(m-1))/2;
    for(auto p : nodesum) {
        ll value = p.second;
        ans -= value*(value-1)/2;
    }
    cout << ans << "\n";
}

