#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n;
    cin >> n;
    vector<ll> S(n+1);
    for(ll i = 2;i<=n;i++) {
        ll d;
        cin >> d;
        S[i] = S[i-1] +d;
    }
    for(ll i = 1;i<=n-1;i++) {
        for(ll j = 1;j<=n-i;j++) {
            cout << S[i+j] - S[i] << " ";
        }
            cout << "\n";
    }

}