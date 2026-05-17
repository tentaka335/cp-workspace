#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector<ll> A(n+1);

    for(ll i = 1;i<=n;i++) {
        A[i] = i;
    }
    bool rev = false;
    for(ll qi = 0;qi<q;qi++) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x,y;
            cin >> x >> y;
           if(rev==true) A[n+1-x] = y;
           else A[x] = y;
        }
        if(qt==2) {
            if(rev==true) rev = false;
            else rev = true;
        }
        if(qt==3) {
            ll x;
            cin >> x;
            cout << (rev?A[n+1-x]:A[x]) << "\n";
        }
    }
}