#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
  ll n,ans = 0;
  cin >> n;
  
  for (ll i = 0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    if (a < b) ans++;
  }
  cout << ans << "\n";
}