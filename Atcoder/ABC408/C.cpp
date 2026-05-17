#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,m;
    cin >> n >> m;
    vector<ll> S(n+2);
    vector<ll> imos(n+2);
    for(ll i = 0;i<m;i++) {
        ll l,r;
        cin >> l >> r;
        imos[l]++;
        imos[r+1]--;
    }
    ll ans = m;
    for(ll i =1;i<=n;i++) {
        S[i] = S[i-1] + imos[i];
        ans = min(ans,S[i]);
    }
    cout << ans << "\n";
}