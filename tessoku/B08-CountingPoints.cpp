#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<vector<ll>> grit(1501,vector<ll>(1501,0));
    vector<vector<ll>> sum(1501,vector<ll>(1501,0));

    for(ll i=0; i<N; i++) {
        ll x,y;
        cin >> x >> y;
        grit[x][y] ++;
    }

    for(ll i=1; i<=1500; i++) {
        for(ll j=1; j<=1500; j++) {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] -sum[i-1][j-1] + grit[i][j];
        }
    }
    ll Q;
    cin >> Q;
    for (ll i=0; i<Q; i++) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << sum[c][d]-sum[c][b-1]-sum[a-1][d] +sum[a-1][b-1] << endl;
    }
}