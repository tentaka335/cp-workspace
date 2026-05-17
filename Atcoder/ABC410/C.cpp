#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,q;
    cin >> n >> q;
    vector<ll> B(2*n);
    for (ll i = 0;i<2*n;i++) {
        B[i] = (i%n)+1;
    }
    ll ksum = 0;
    for(ll i = 0;i<q;i++) {
        ll t;
        cin >> t;
        if(t==1) {
            ll p,x;
            cin >> p >> x;
            B[ksum+p-1] = x;
            B[(ksum+p+n-1)%(2*n)] = x;
        }
        else if (t == 2) {
            ll p;
            cin >> p;
            cout << B[ksum+p-1] << "\n";
        }
        else if (t == 3) {
            ll k;
            cin >> k;
            ksum =(ksum+k)%n;
        }
    }
}