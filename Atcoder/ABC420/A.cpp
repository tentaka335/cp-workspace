#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll x,y;
    cin >> x >> y;
    if ((x+y)%12 == 0) cout << 12 << "\n";
    else cout << (x+y)%12 << "\n";
}