#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    ll ans = 1000000;
    for(ll i = 0;i<=n-m;i++) {
        ll count = 0;
        for(ll j = 0;j<m;j++) {
            ll tj = t[j] - '0';
            ll sj = s[i+j] - '0';
            if(tj<=sj) count +=sj-tj;
            else count += 10 - tj+sj;
        }
        ans = min(ans,count);
    }
    cout << ans << "\n";
}