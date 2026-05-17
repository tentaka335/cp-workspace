#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,b,w=1000000007;
    cin >> a >> b;
    ll ans = 1;
    vector<ll> pwr(32);
    pwr[0] = a;
    for (ll i = 1; i<=31;i++) {
        pwr[i] =(pwr[i-1]*pwr[i-1])%w;
    }
    for(ll i = 0;(1 << i) < b ;i++) {
        if ((b >> i) & 1) {
            ans = (ans*pwr[i]) % w;
        }
    }
    cout << ans << "\n";
}