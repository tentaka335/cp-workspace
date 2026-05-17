#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,w;
    cin >> n >> w;
    vector<vector<ll>> DP(n+1,vector<ll>(w+1,-100000000));
    vector<ll> W(n+1),V(n+1);
    for(ll i=1; i<=n; i++) {
        cin >> W[i] >> V[i];
    }
      DP[0][0] = 0;
    for(ll i=1; i<=n; i++) {
        for (ll j=1; j<=w; j++) {
            if(j>=W[i]) DP[i][j] = max(DP[i-1][j],DP[i-1][j-W[i]] + V[i]);
            else DP[i][j] = DP[i-1][j];
        }
    }

    for (ll i=0; i<=n; i++) {
        for (ll j=0; j<=w; j++) {
           if(DP[i][j]>=0) cout << DP[i][j] << " ";
           else cout << 0 << " ";
        }
        cout << "\n";
    }
    
    cout << DP[n][w] << endl;
}