#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n),a(n);
    for (ll i=0; i<n; i++) {
        cin >> A[i];
        a[i] = A[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    for(ll i=0;i<n; i++) {
        ll b = lower_bound(a.begin(),a.end(),A[i]) - a.begin()+1;
        cout << b << " ";

    }
}