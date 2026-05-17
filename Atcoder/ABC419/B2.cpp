#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    ll q;
    cin >> q;
    map<ll,ll> A;
    for (ll i = 0; i<q; i++) {
        ll que;
        cin >> que;
        if (que == 1) {
            ll x;
            cin >> x;
            if (!A.count(x)) {
                A[x] = 1;
            }
            else A[x] +=1;
        }
        else {
            auto it = A.begin();
            cout << it->first << "\n";
            if(--(it->second) == 0) A.erase(it);
        }
    }
}  
