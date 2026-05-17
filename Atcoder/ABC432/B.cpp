#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll x;
    cin >> x;
    string xs = to_string(x);
    vector<ll> X(xs.size());
    for (ll i = 0;i<xs.size(); i++) {
        X[i] = xs[i]-'0';
    }
    sort(X.begin(),X.end());
    ll zero = 0;
    for (ll i = 0; i<X.size(); i++) {
        if(X[i] == 0) {
            zero ++;
        }
        else if(X[i]>0) {
            cout << X[i];
                for (ll j = 0;j<zero;j++) {
                    cout << 0;
                }
                zero = 0;
        }

}
cout << "\n";
}