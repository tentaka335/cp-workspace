#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> DP(2009,vector<ll>(2009,0));
    for(ll i = 1;i<=n;i++) cin >> DP[n][i];

    for(ll i = n-1;i>=1;i--) {//i段目を代入
        for(ll j = 1;j<=i;j++) {
             if(i%2 == 1) {
            DP[i][j] = max(DP[i+1][j],DP[i+1][j+1]);
        }
         if(i%2 == 0) {
            DP[i][j] = min(DP[i+1][j],DP[i+1][j+1]);
        }
        }
    }
    cout << DP[1][1] <<"\n";
}