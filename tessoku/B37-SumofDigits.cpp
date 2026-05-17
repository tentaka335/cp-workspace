#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s = to_string(n);
    ll ans = 0;
    for(ll i = 0;i<s.size()-1;i++) {
        ans += s[i] - '0';
    }
    cout << ans << "\n";
}