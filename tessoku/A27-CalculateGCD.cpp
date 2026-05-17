#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {
    
    if (y<x) swap(x,y);
    while (true) {
        ll r = y%x;
        if (r == 0) {
            return x;
        }
        else {
            y = x;
            x = r;
        }
    }
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;
    cout << gcd(a,b) << "\n";

}