#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n+1),H(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
        H[i] = i + A[i]-1;
    }
    ll ans = 1;
    for(ll i =1;i<=n;i++) {
        ans = max(ans,H[i]);
        if(ans == i && ans <=n) {
            cout << ans << "\n";
            return 0;
        }
        if (ans >= n) {
            cout << n << "\n";
            return 0;
        }
        
    }
}