#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    
    ll left = (n+1)/2;
    ll ans = 0;
    rep(i,n/2) {
        if(left>=n) break;
        ll pos = lower_bound(A.begin()+left,A.end(),2*A[i]) - A.begin();
        if(pos==n) break;
        ans++;
        left = pos + 1;

    }
    cout << ans << "\n";
    
    return 0;
}