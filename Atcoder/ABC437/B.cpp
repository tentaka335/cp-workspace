#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w,n;
    cin >> h >> w >> n;
    vector<set<ll>> A(h+9);
    vector<ll> Ans(h+9,0);
    for(ll i = 0;i<h;i++) {
        for(ll j = 0;j<w;j++) {
            ll a;
            cin >> a;
            A[i].insert(a);
        }
    }
    for(ll i = 0;i<n;i++) {
        ll b;
        cin >> b;
        for(ll j = 0;j<h;j++) {
            if(A[j].count(b)) Ans[j]++;
        }
    }
    ll ans = 0;
    for(ll i = 0;i<h;i++) ans = max(ans,Ans[i]);
    cout << ans << "\n";
}