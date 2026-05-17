#include <bits/stdc++.h>
using namespace std;
using ll = long long;

    ll n,x,A[100009];
ll binaryarraysearch (ll x) {
    ll pos = lower_bound(A + 1,A+n+1, x) - A;
    cout << A <<'\n';
    if (pos <=n && A[pos] == x) return pos;
    return -1;
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (ll i=1; i<=n; i++) cin >> A[i];
    cout << binaryarraysearch(x) << endl;
}