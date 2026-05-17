#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll H,W,N;
    cin >> H >> W >> N;
    vector<vector<ll>> X(1509,vector<ll>(1509,0));
    vector<vector<ll>> sum(1509,vector<ll>(1509,0));
    for (ll i=0; i<N;i++) {
        ll A,B,C,D;
        cin >> A >> B >> C >> D;
        X[A][B]++;
        X[C+1][D+1] ++;
        X[A][D+1] --;
        X[C+1][B] --;
    }
    for (ll i =1; i<=H; i++) {
        for (ll j=1; j<=W;j++) {
            sum[i][j] = sum[i][j-1] + X[i][j];
        }
    }

    for (ll i =1; i<=H; i++) {
        for (ll j=1; j<=W;j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j];
        }
    }

     for (ll i =1; i<=H; i++) {
        for (ll j=1; j<=W;j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    
    

}