#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S,T;
    cin >> S >> T;
    ll s=S.size(),t=T.size();
    vector<vector<ll>> DP(s+1,vector<ll>(t+1,0));
   for(ll i = 1; i<=s; i++) {
    for (ll j = 1; j<=t; j++) {
        if (S[i-1]==T[j-1]) DP[i][j] = max({DP[i-1][j],DP[i][j-1],DP[i-1][j-1]+1});
        else DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
    }
   }
   cout << DP[s][t] << endl;
}
