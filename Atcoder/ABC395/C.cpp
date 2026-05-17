#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<vector<ll>> inverseA(1000009);
    ll ans = 100000000000;
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        inverseA[A[i]].push_back(i);
        if(inverseA[A[i]].size()>=2) {
            ans = min(ans,inverseA[A[i]][inverseA[A[i]].size()-1]-inverseA[A[i]][inverseA[A[i]].size()-2]+1);
        }
  }
  if(ans==100000000000) cout << -1 << "\n";
  else cout << ans << "\n";
}