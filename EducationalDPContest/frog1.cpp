#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> H(n+1);
    vector<ll> DP(n+1);
    for(ll i = 1;i<=n;i++) cin >> H[i];
    DP[1] = 0;
    DP[2] = llabs(H[2]-H[1]);
    for(ll i = 3;i<=n;i++) {
        DP[i] = min(DP[i-1]+llabs(H[i]-H[i-1]),DP[i-2]+llabs(H[i]-H[i-2]));
    }
    cout << DP[n] << "\n";
}