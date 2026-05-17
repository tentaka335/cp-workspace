#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,l;
    cin >> n >> l;
    ll sum = 0;
    vector<ll> P(l,0);//0からの距離がiの点
    P[0] = 1;
    for(ll i = 0;i<n-1;i++) {
        ll d;
        cin >> d;
        sum = (sum + d)%l;
        P[sum] ++;
    }
    if(l%3!=0) {
        cout << 0 << "\n";
        return 0;
    }
    ll ans = 0;
    for(ll i = 0;i<l/3;i++) {
        ans+=P[i]*P[l/3+i]*P[2*(l/3)+i];
    }
    cout << ans << "\n";
}