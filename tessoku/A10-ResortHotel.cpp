#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n+9,0);
    for (ll i=1; i<=n; i++) {
        cin >> A[i];
    }
    vector<ll> leftmax(n+9,0);
    vector<ll> rightmax(n+9,0);
    for (ll i=1; i<=n; i++) {
        leftmax[i] = max(leftmax[i-1],A[i]);
        rightmax[n+1-i] = max(rightmax[n+1-i+1],A[n+1-i]);
    }

    ll d;
    cin >> d;
    while(d--) {
        ll l,r;
        cin >> l >> r;
        cout << max(leftmax[l-1],rightmax[r+1]) << endl;
    }
}