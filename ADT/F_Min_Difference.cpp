#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n),B(m);
    rep(i,n) cin >> A[i];
    rep(i,m) cin >> B[i];
    ll ans = inf;
    sort(all(B));
    rep(i,n) {
        ll a = A[i];
       auto it = lower_bound(all(B),a);
       
       if(it==B.end()) {
        chmin(ans,llabs(a-B[m-1]));
       }
       else if (it==B.begin()) {
        chmin(ans,llabs(a-B[0]));
       }
       else {
            ll pos = it - B.begin();
            chmin(ans,llabs(a-B[pos]));
            chmin(ans,llabs(a-B[pos-1]));
       }
    }

    cout << ans;
    
    return 0;
}