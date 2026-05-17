#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n+1,0),S(n+1,0),R(n+1,0);
    for (ll i=1; i<=n; i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }

    for(ll i=1;i<=n;i++) {
        if(i==1) {
            R[i] = n;
        } else if (i==n) {
            R[i] = n;
        } else {
            R[i] = R[i-1];
        }
        while(R[i]<n && S[R[i]+1]-S[i-1] <= k) {
            R[i] += 1;
        }
}
 ll ans = 0; 
    for (ll i=1; i<=n; i++) ans +=R[i]-i+1;
    cout << ans << endl; 
}