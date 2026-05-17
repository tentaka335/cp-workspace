#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll X,C;
    cin >> X >> C;
    ll Y = X-X%1000;
    while ( Y*1000+Y*C>1000*X) {
        Y-=1000;
    }
    if (Y > 0) {
        cout << Y << endl;
    } else {
        cout << 0 << endl;
    }
    

}