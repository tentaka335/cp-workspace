#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll i = 0;i<t;i++) {
        ll n;
        string s;
        cin >> n >> s;
        vector<bool> DP(300000);
        DP[0] = true;
        for(ll j = 0;j< (1 << n) - 1;j++) {
            if(DP[j] == false) continue;
            for(ll k = 0;k<n;k++) {
                if(((j >> k) & 1) == 0 && s[j + (1 << k)-1] == '0') DP[j + (1 << k)] = true;
            }
        }
        if(DP[(1 << n) - 1] == true) cout << "Yes" << "\n";
        else cout << "No" << "\n";
      }
}

//      if(j + (1 << k) >(1 << n) - 1) break;