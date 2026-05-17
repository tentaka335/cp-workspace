#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> P(n+1),A(n+1);
    for (ll i=1; i<=n; i++) cin >> P[i] >> A[i];

    vector<vector<ll>> DP(n+2,vector<ll>(n+2,0));

    for (ll i = 1;i<=n;i++) {
        for(ll j = n; j>=1;j--) {
            if (i>j) break;
            ll score1 = 0;
            if (i-1<=P[i-1] && P[i-1]<= j) score1 = A[i-1];
            ll score2 = 0;
            if (i<=P[j+1] && P[j+1] <= j+1) score2 = A[j+1];

            DP[i][j] = max(DP[i-1][j] + score1, DP[i][j+1] + score2);
        }
    }
    for (ll i = 1;i<=n;i++) {
        for(ll j = 1; j<=n; j++) {
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    ll ans = 0;
    for (ll i=1; i<=n;i++) ans = max(DP[i][i],ans);
    cout << ans << "\n";
}