#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,s;
    cin >> n >> s;
    vector<ll> A(n+1);
    vector<vector<bool>> DP(n+1,vector<bool>(s+1,false));

    for (ll i=1; i<=n; i++) cin >> A[i];
    for (ll i=0; i<=n; i++) DP[i][0] = true;
    for (ll i=1; i<=n; i++) {
        for(ll j = 1; j<=s; j++) {
            if (DP[i-1][j]) DP[i][j] = true;
            else if (j-A[i] >=0&&DP[i-1][j-A[i]]) DP[i][j] = true;
        }
    }
    bool ans = false;
    for (ll i = 0 ; i<=n; i++) if (DP[i][s]) ans = true;

    if (ans) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}