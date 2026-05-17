#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, ans = 0;
    cin >> n;
    
    for (ll i=1; i<=n; i++) {
        ll k = i%2 ;
        if (k==0) ans += i*i*i;
        else ans += -1*i*i*i;
    }
    cout << ans << endl;
}
