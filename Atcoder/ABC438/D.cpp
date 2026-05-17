#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n+1),B(n+1),C(n+1),SA(n+1),SB(n+1),SC(n+1),D(n+1),SD(n+1),X(n+1);
    for(ll i = 1;i<=n;i++)     cin >> A[i];
    for(ll i = 1;i<=n;i++)     cin >> B[i];
    for(ll i = 1;i<=n;i++)     cin >> C[i];

    for(ll i = 1;i<=n;i++) {
        D[i]= A[i] - B[i];
        SA[i] = SA[i-1] + A[i];
        SB[i] = SB[i-1] + B[i];
        SC[i] = SC[i-1] + C[i];
        if(i>=2) {
            SD[i] = SD[i-1] + D[i];
        }
        else SD[i] = 0;
    }//あとはx,yを見つけるだけ！
     ll maxsd = 0;
     X[1] = 1;//X[i] は i以下でのxにすると良い値。
    for(ll i = 2;i<=n;i++) { //ほんとはn-21までで良い
        if(SD[i]>maxsd) {
            X[i] = i;
            maxsd = SD[i];
        }
        else X[i] = X[i-1];
    }
    ll ans = 0;
    ll perx;
    ll pery;
    for(ll y = 2;y<=n-1;y++) {
        ll goodx = X[y-1];
        ll a = SA[goodx];
        ll b =  SB[y] - SB[goodx];
        ll c = SC[n] - SC[y];
        if(a+b+c>=ans) {
            perx = goodx;
            pery = y;
        }
        ans = max(ans,a+b+c);
    }
    cout << ans << "\n";
}