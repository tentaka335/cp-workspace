#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    ll q;
    cin >> q;
    vector<ll> A(109,0);
    for (ll i = 0; i<q; i++) {
        ll que;
        cin >> que;
        if (que == 1) {
            ll x;
            cin >> x;
            A[x] += 1;
        }
        else {
            for (ll j=1; j<=100; j++) {
                if (A[j]>=1) {
                    cout << j << endl;
                    A[j] -=1;
                    break;
                }
            }
        }
    }
}  
