#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> H(n);
    vector<ll> B(m);
    for (ll i = 0; i<n;i++) cin >> H[i];
    for (ll i = 0; i<m;i++) cin >> B[i];

    sort(H.begin(),H.end());
    sort(B.begin(),B.end());
    ll left = 0;
    for (ll i = 0; i<k;i++) {
        auto it = lower_bound(B.begin()+left,B.end(),H[i]);
        if (it == B.end()) {
            cout << "No" << "\n";
            return 0;
        }
        else {
            ll s = it - B.begin();
            left = s + 1;
        }
    }
    cout << "Yes" << "\n";
}