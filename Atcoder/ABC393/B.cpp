#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    for(ll i = 0;i<n-2;i++){
        for(ll j = i + 1;j<n-1;j++) {
            for(ll k = j + 1;k<n;k++) {
                if(2*j==k+i&&s[i]=='A'&&s[j]=='B'&&s[k]=='C')ans ++;
            }
        }
    }
    cout << ans << "\n";
}


