#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n),B(n);
    for(ll i = 0;i<n;i++) cin >> A[i];
    for(ll i = 0;i<n;i++) cin >> B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll ans = 0;
    for(ll i = 0;i<n;i++) ans+=llabs(A[i]-B[i]);
    cout << ans << "\n";
}