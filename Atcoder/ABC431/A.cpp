#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,b;
    cin >> h >> b;
    if(h > b) cout << h - b << "\n";
    else cout << 0 << "\n";
}