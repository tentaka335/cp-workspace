#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,nimsum;
    cin >> n ;
    for ( ll i = 0;i < n;i++) {
        ll a;
        cin >> a;
        if (i == 0) nimsum = a;
        else {
            nimsum = nimsum^a;
        }
    }
    if (nimsum != 0) cout << "First" << "\n";
    else cout << "Second" << "\n";
}