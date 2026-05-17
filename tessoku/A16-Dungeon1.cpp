#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> A(n+1),B(n+1),DP(n+1);
    for (ll i=2; i<=n; i++) cin >> A[i];
    for (ll i=3; i<=n; i++) cin >> B[i];

    DP[2] = A[2];

    for (ll i=3; i<=n; i++) {
    DP[i] = min((DP[i-1]+A[i]),(DP[i-2]+B[i]));
    }

    cout << DP[n] << "\n";
}