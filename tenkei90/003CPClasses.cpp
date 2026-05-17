#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    set<ll> A;
    for(ll i = 0;i<n;i++) {
        ll a;
        cin >> a;
        A.insert(a);
    }
    ll q;
    cin >> q;
    for(ll i = 0;i<q;i++) {
        ll b;
        cin >> b;
        ll ans;
        auto it = A.lower_bound(b);
        if(it==A.begin()) {
            ans = llabs(*it-b);
        }
        else if(it==A.end()) {
            it--;
            ans = llabs(b-*it);
        }
        else {
            auto right = it;
            auto left = --it;
            ans = min(llabs(*right-b),llabs(*left-b));
        }
        cout << ans << "\n";
    }
}