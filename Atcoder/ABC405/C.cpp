#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n;
    cin >> n;
    vector<ll> A(n),S(n);
    
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        if(i==0) S[i] = A[i];
        else S[i] = S[i-1] + A[i];
    }
    ll ans = 0;
    for(ll i = 0;i<n-1;i++) {
        ans +=A[i]*(S[n-1]-S[i]);
    }
    cout << ans << "\n";
}