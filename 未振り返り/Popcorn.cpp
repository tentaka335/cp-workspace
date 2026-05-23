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
    
    ll n,m;
    cin >> n >> m;
    vector<string> S(n);
    rep(i,n) {
        cin >> S[i];
    }
    ll ans = inf;
    for(ll i = 0;i<((ll)1<<n);i++) {
        vector<bool> can(m);
        bool ok = true;
        ll cnt = 0;
        for(ll j = 0;j<n;j++) {
            
            if(((i>> j)&1) == 1) {
                cnt++;
                for(ll k = 0;k<m;k++) {
                    if(S[j][k]=='o') can[k] = true;
                }
                
            }
        }
        rep(j,m) {
            if(can[j] == false) ok = false;
        }
        if(ok == true) chmin(ans,cnt);
    }

    cout << ans << "\n";
    
    return 0;
}