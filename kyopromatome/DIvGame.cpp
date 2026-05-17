#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll c = 0;
    
    vector<pair<long long, int>> ret;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int a = 0;
      while (n % i == 0) {
        a++;
        n /= i;
      }
      ret.push_back(pair(i, a));
    }
  }
  if (n > 1){
    ret.push_back(pair(n, 1));
  }
  for (ll i = 0; i < ret.size(); i++) {
  ll j = 0;
  while (j*j+j <= 2*ret[i].second) {
    j++;
  }
 c += j;
}
cout << c <<"\n";
}
