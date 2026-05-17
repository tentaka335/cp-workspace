#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << "Yes" << endl;
        return 0;
    } else if (b==c) {
         cout << "Yes" << endl;
        return 0;
    }
    else if (c==a) {
         cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    

}