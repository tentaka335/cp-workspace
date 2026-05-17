#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string s;
    cin >> s;
   ll len = s.size();
   ll ans = 0;
   ll b = 0;
   for (ll i = len-1;i>=0;i--) {
    ll k = s[i] - '0';
    k = (10 + k - b) % 10;
    ans += k + 1;
    b = (b+k)%10;
   }
   cout << ans << "\n";
}