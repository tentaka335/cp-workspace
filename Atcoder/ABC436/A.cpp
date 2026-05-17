#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    string s;
    cin >> n >> s;
    ll a = n - s.size();
    string ans;
    for(ll i = 0;i<a;i++) {
        ans+="o";
    }
    ans += s;
    cout << ans << "\n";
}