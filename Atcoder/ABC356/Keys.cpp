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
    
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> C(m);
    vector<vector<ll>> A(m);
    vector<char> R(m);

    rep(i,m) {
       
        cin >> C[i];
        rep(j,C[i]) {
            ll a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
      cin >> R[i];
    }
    ll ans = 0;
    for(ll i = 0;i<((ll)1<< n);i++) {
        bool ok = true;
        rep(j,m) {
             ll keynum = 0;
            rep(l,C[j]) {
                if(((i >> A[j][l]) & 1) == 1) keynum ++;
            }
            if(keynum>=k&&R[j] == 'x') {
                ok = false;
                continue;
            }
            if(keynum< k &&R[j]=='o') {
                ok = false;
                continue;
            }
        }
        if(ok == true) ans++;
    }

    cout << ans << "\n";

    return 0;
}