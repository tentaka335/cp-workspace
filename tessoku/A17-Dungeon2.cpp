#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> A(n+1),B(n+1),DP(n+1),DP2(n+1),DP3;
    for (ll i=2; i<=n; i++) cin >> A[i];
    for (ll i=3; i<=n; i++) cin >> B[i];
    DP2[1] = 1;
    DP2[2] = 1;
    DP[2] = A[2];

    for (ll i=3; i<=n; i++) {
    DP[i] = min((DP[i-1]+A[i]),(DP[i-2]+B[i]));
    if (DP[i] == DP[i-1]+A[i]) DP2[i] = i-1;
    else if (DP[i] == DP[i-2]+B[i]) DP2[i] = i-2;
    }
    for(ll i=n; i>1; i = DP2[i]) {
        DP3.push_back(DP2[i]);
        if (i==1) break;
    }
  reverse(DP3.begin(),DP3.end());
  cout << DP3.size() + 1 << endl;
    for (ll i=0; i<DP3.size(); i++) {
        cout << DP3[i] << " ";
    }
    cout << n << endl;
}