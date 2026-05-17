#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    cin >> a >> b;
    for (ll i = 0; i<8; i++) {
    auto wa = to_string(a+b);
    reverse(wa.begin(),wa.end());
     c = stol(wa);
     a = b;
     b = c;
    }

    cout << c << endl;
     
}