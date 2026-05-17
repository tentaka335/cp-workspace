#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll smax = 1;
    for (ll s = 1; s*s<=n; s++) {
        if (n%s == 0) {
            smax = s;
        }
    
    }

    cout << smax + n/smax -2 << "\n";

    

}