#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n+9),B(n+9),DP(n+9,-15000000000);
    vector<bool> DP2(n+9);
    DP[1] = 0;
    for (ll i=1; i<=n-1; i++) cin >> A[i];
    for (ll i=1; i<=n-1; i++) cin >> B[i];

    for (ll i=1; i<=n-1; i++) {
         
        DP2[A[i]] = true;
        DP2[B[i]] = true;
        DP[A[i]] = max(DP[i]+100,DP[A[i]]);
        DP[B[i]] = max(DP[i]+150,DP[B[i]]);
        
    }
    cout << DP[n] << "\n";
}