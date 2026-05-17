#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> H(n+1);
    vector<ll> DP(n+1,999999999999999);
    for(ll i = 1;i<=n;i++) cin >> H[i];
    DP[1] = 0;
    for(ll i = 1;i<n;i++) {
        for(ll j = 1;j <=k;j++) {
            if(i+j<=n) {
                DP[i+j] = min(DP[i+j],DP[i]+llabs(H[i+j]-H[i]));
            }
        }
    }
    cout << DP[n] << "\n";
}