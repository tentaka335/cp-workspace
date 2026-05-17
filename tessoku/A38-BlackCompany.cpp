#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll d,n;
    cin >> d >> n;
    vector<ll> L(n),R(n),H(n),D(366,24);
    for(ll i = 0;i<n;i++) cin >> L[i] >> R[i] >> H[i];

    for(ll i = 1;i<=d;i++) {
        for(ll j = 0;j<n;j++) {
            if(L[j] <= i && i <= R[j]) {
                D[i] = min(D[i],H[j]);
            }
        }
    }
    ll ans = 0;
    for(ll i = 1;i<=d;i++) ans+=D[i];
    cout << ans << "\n";
}