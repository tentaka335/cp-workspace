#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,s;
    cin >> n >> s;
    vector <ll> A(n+1);
    for (ll i=1; i<=n; i++) cin >> A[i];

    vector<vector<vector<ll>>> DP1(n+9,vector<vector<ll>>(s+9,vector<ll>(1,0)));
    vector<vector<bool>> DP2(n+9,vector<bool>(s+9));

    for (ll i=0;i<=n;i++) DP2[i][0] = true;

    for (ll i = 1; i<=n; i++) {
        for (ll j = 1; j<=s; j++) {
            if (DP2[i-1][j]) {
                DP2[i][j] = true;
                DP1[i][j] = DP1[i-1][j];
            }
            if (j>=A[i] && DP2[i-1][j-A[i]]) {
                DP2[i][j] = true;
                DP1[i][j] = DP1[i-1][j-A[i]];
                DP1[i][j].push_back(i);
             }
        }
    }
    for (ll i = 1; i<=n; i++) {
        if(DP2[i][s]) {
            cout << DP1[i][s].size()-1 << "\n";
            for (ll j=1; j<=DP1[i][s].size()-1; j++) {
                cout << DP1[i][s][j] << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}