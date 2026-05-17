#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 ll x,n;
 cin >> x >> n;
 vector<ll> W(n+1);
 vector<bool> P(n+1,false);
 for (ll i = 1; i<=n;i++) cin >> W[i];
 ll q;
 cin >> q;
 ll sum = x;
 for (ll i = 0; i<q; i++) {
    ll p ;
    cin >> p;
    if (P[p]){
        P[p] = false ;
        sum -= W[p];
        cout << sum << "\n";
    }
    else {
        P[p] = true;
        sum += W[p];
        cout << sum << "\n";
    }
    ve
 }
}