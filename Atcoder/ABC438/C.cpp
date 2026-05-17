#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1;i<=n;i++) {
        ll k = i/3;
        ll x = i&k;
        cout << x << "\n";
    }
}