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
    
    ll t;
    cin >> t;
    rep(ti,t) {
        ll n;
        cin >> n;
        vector<ll> P(n),W(n),PW(n);
        ll sump = 0;
        rep(i,n) {
            cin >> W[i] >> P[i];
            PW[i]  = P[i] + W[i];
            sump +=P[i];
        }
        sort(all(PW));

        ll ans = 0;
        for(ll i = 0;i<n;i++) {
            if(sump - PW[i] >=0) {
                ans++;
                sump -= PW[i];
            }
            else break;
        }
        cout << ans << "\n";
    }

    
    
    return 0;
}