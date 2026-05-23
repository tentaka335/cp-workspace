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
    cin >> n ;

    vector<Pll> inter(n);
    rep(i,n) {
        ll l,r;
        cin >> l >> r;
        inter[i] = {l,r};
    }
    sort(all(inter));
    vector<ll> A;
 
    
    ll ans = 0;
    rep(i,n) {
        auto [l,r] = inter[i];
        ll pos  = upper_bound(all(inter),make_pair(r+1,r+1))- inter.begin();
        pos--;
        ans+= pos - i;
    }
    cout << ans << "\n";
    return 0;
}