#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll s, p;
    cin >> s >> p ;
  
    for (ll n=1; n * n <= p;  n++) {
        if (p%n == 0) {
            ll m = p/n;
            if (n + m == s) {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }
   cout << "No" << "\n";
}