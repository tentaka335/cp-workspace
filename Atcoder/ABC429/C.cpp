#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    map<ll,ll> A;
    
    ll ans = 0;
    for (ll i=0; i<n;i++) {
        ll x;
        cin >> x;
        if (!A.count(x)) {
            A[x] =1;
        }
        else A[x] +=1;
    }
    for (auto p : A) {
        ll l = p.second;
        ll c = l*(l-1)/2;
        ans += c*(n-l);
    }
    cout << ans << "\n";
}