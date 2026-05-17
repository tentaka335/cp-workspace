#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,ans=0;
    cin >> n;

    vector<vector<ll>> X(1509,vector<ll>(1509,0));
        vector<vector<ll>> sum(1509,vector<ll>(1509,0));
        for (ll i=0; i<n; i++) {
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            X[a+1][b+1] ++;
            X[c+1][d+1]++;
            X[a+1][d+1] --;
            X[c+1][b+1] --;
        }
        for(ll i =1; i<=1502 ; i++) {
            for(ll j=1; j<= 1502; j++) {
                sum[i][j] = sum[i][j-1]+X[i][j];
            }
        } 
         for(ll i =1; i<=1502 ; i++) {
            for(ll j=1; j<= 1502; j++) {
                sum[i][j] = sum[i-1][j]+sum[i][j];
            }
        }
         for(ll i =1; i<=1502 ; i++) {
            for(ll j=1; j<= 1502; j++) {
                if(sum[i][j]>=1) ans++;
        }
}
 cout << ans << endl;
}