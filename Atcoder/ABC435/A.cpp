#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> S(n);
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        if (i>=1) {
            S[i] = S[i-1] + A[i];
        }
        else S[i] = A[i];
    }
    ll ans = 0;
    for (ll l = 0;l<=n-1;l++) {
        for(ll r = l;r<=n-1;r++) {
            ll sum = S[r] - S[l] + A[l];
            ll ok = true;
            for(ll i = l;i<=r;i++) {
                if(sum%A[i] == 0) {
                    ok = false;
                    break;
                }
            }
            if(ok == true) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}