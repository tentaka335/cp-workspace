#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll q;
    cin >> q;
    set<ll> S;
    for(ll qi = 0;qi<q;qi++) {
        ll qt,x;
        cin >> qt >> x;
        if(qt==1) S.insert(x);
        if(qt==2) S.erase(x);
        if(qt==3) {
            auto it = S.lower_bound(x);
            cout << (it == S.end()?-1:*it) << "\n";
        }
    }
 }