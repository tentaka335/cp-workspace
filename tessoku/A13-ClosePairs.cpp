#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n+1),R(n+1);

    for (ll i=1; i<=n; i++) cin >> A[i];

    for (ll i=1; i<=n; i++) {
        if (i==1) R[i] = 1;
        else R[i] = R[i-1];
        
        while(R[i]<n && A[R[i]+1]-A[i]<=k) {
            R[i] += 1;
        }
    }
    ll ans = 0;
    for (ll i=1; i<=n-1; i++) ans+=R[i]-i;
    cout << ans << "\n";
}