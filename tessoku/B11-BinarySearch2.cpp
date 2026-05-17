#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    ll q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        auto it = lower_bound(A.begin(), A.end(), x);
        ll pos = it - A.begin(); // 0-based index
            cout << (pos) << '\n'; // 1-based を出力したいなら +1
    }
    return 0;
}