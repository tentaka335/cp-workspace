#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll h,w,n;
    cin >> h >> w >> n;
    vector<set<ll>> X(h+9),Y(w+9);
    for(ll i = 0;i<n;i++) {
        ll x,y;
        cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    ll q;
    cin >> q;
    for(ll i = 0;i<q;i++) {
        ll qt;
        cin >> qt;
        if(qt == 1) {
            ll x;
            cin >> x;
            cout << X[x].size() << "\n";
            for(auto &y : X[x]) {
                Y[y].erase(x);
            }
            X[x].clear();
        }
            if(qt == 2) {
            ll y;
            cin >> y;
            cout << Y[y].size() << "\n";
            for(auto &x : Y[y]) {
                X[x].erase(y);

            }
            Y[y].clear();
        }
    }
}