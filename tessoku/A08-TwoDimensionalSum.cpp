#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> X(H+1,vector<ll>(W+1,0));
    vector<vector<ll>> sumH(H+1,vector<ll>(W+1,0));
     vector<vector<ll>> sum(H+1,vector<ll>(W+1,0));
    for (ll i=1; i<=H; i++) {
        for (ll j=1; j<=W; j++) {
            cin >> X[i][j];
            sumH[i][j] = sumH[i][j-1] + X[i][j];
            sum[i][j] = sum[i-1][j] + sumH[i][j];

        }
    }
    ll Q;
    cin >> Q;
    for (ll i=0;i<Q; i++) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1] << endl;
    }
}