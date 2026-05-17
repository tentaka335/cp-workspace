#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i < (int)(n); i++)
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> A(n);
    rep(i,0,n) cin >> A[i];
    sort(A.begin(),A.end());
    ll ans = A[0];
    ll bunbo = y-x;
    rep(i,1,n) {
        ll bunsi = x*(A[i]-A[0]);
        ll D = bunsi/bunbo;
        if(bunsi % bunbo != 0 || bunsi/bunbo > A[0]) {
            cout << -1 << "\n";
            return 0;
        }
        ans +=A[0]-D;
    }
    cout << ans << "\n";
}