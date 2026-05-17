#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll i = 0;i<t;i++) {
    ll n,m;
    cin >> n >> m;
    if(m%2 == 1)cout << (m/2)*n+1 << "\n";
    else cout << (m/2)*n << "\n";
    }
}