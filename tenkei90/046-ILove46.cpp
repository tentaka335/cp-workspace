#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n),B(n),C(n);
    map<ll,ll> MA,MB,MC;

    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        MA[A[i]%46]++;
    }

     for(ll i = 0;i<n;i++) {
        cin >> B[i];
        MB[B[i]%46]++;
    }

     for(ll i = 0;i<n;i++) {
        cin >> C[i];
        MC[C[i]%46]++;
    }

    
    ll ans = 0;
    for(auto a:MA) {
        ll akey = a.first;
        ll avalue = a.second;
         for(auto b:MB) {
        ll bkey = b.first;
        ll bvalue = b.second;
         for(auto c:MC) {
        ll ckey = c.first;
        ll cvalue = c.second;

        if((akey+bkey+ckey)%46==0) ans+=avalue*bvalue*cvalue;
    }

    }
    }
    cout << ans << "\n";
}




/*
A,B,Cに含まれる数をそれぞれ46で割った余りによって分類。（mapを用いる）
余りはA,B,Cごとに高々46通りだから、3種の余りを全探索する。
*/



