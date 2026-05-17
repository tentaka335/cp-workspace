#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    string ans = s.substr(a,s.size()-a-b);
    cout << ans << "\n";
}
