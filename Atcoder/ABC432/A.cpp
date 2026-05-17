#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  ll a,b,c;
  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(),A.end());
  for (ll i = 2 ; i>=0; i--) cout << A[i];
  cout << "\n";
}