#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    vector<ll> X(q);
    for (ll i = 0;i<q;i++) cin >> X[i];
    for (ll i = 0; i<q;i++) {
        bool is_prime = true;
        for (ll j = 2; j*j <= X[i];j++) {
            if (X[i] % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}