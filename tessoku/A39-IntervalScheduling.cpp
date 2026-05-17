#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> DP(86409);//その時間から見れる映画の個数
    vector<set<ll>> L(86409);
    for(ll i = 0;i<n;i++) {
        ll l,r;
        cin >> l >> r;
        L[l].insert(r);
    }
    for(ll i = 86399;i>=0;i--) {
        DP[i] = DP[i+1];
        if(L[i].size()>=1) {
           ll r=*begin(L[i]);
           DP[i] = max(DP[r]+1,DP[i]);
        }
    }
    cout << DP[0] << "\n";
}