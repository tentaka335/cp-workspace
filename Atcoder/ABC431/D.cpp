#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n ;
    cin >> n ;
    vector<ll> W(n+1),H(n+1),B(n+1);

    ll sumw = 0;
    ll sumv = 0;
    for (ll i =1; i<=n;i++) {
        cin >> W[i] >> H[i] >> B[i];
        sumw += W[i];
        sumv += B[i];
        
    }
     vector<vector<ll>> DP(n+9,vector<ll>(2500009,0));
     for
}