#include <bits/stdc++.h>
using namespace std;
using ll = long long;

 ll n, k,A[100009];

bool check(ll x) {
     ll count = 0;
    for (ll i=1; i<=n; i++) count += x/A[i];
    if (count >= k) return true;
    return false;
}


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (ll i=1; i<=n;i++) cin >> A[i];
    ll left = 1,right = 1'000'000'000;
    while (left < right) {
        ll m = (left + right)/2;
        bool islower = check(m);
        if (islower == true) right = m ;
        if (islower == false) left = m + 1;
    }
    cout << left << endl;
}
