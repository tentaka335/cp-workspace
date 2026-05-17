#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,r,a=1,b=1,b1=1,b2=1,m=1000000007;
    vector<ll> A(100000);
    cin >> n >> r;
    for (ll i = 1;i<=n;i++){
        a = (a*i)%m;
    }
    for (ll i = 1;i<=n-r;i++) {
        b1 = (b1*i)%m;
    }
    for (ll i = 1;i<=r;i++){
        b2 = (b2*i)%m;
    }
    b = (b1*b2)%m;
    A[0] = b;
    for (ll i = 1;(1 << i) < m-2;i++) {
        A[i] = (A[i-1]*A[i-1])%m;
    }
    ll mod = 1;
    for (ll i = 0;(1 << i) < m-2;i++) {
       if ((m-2 >> i) & 1) {
       mod = (mod*A[i])%m;
    }
}
  ll ans = (a*mod)%m;
    cout << ans << "\n";
}
