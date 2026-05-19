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
using mint = modint998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<mint> A(n+1),B(m+1),SB(m+1);
    for(ll i = 1;i<=n;i++) {
        ll a;
        cin >> a;
        A[i] = a;
    }
    for(ll i = 1;i<=m;i++) {
        ll b;
        cin >> b;
        B[i] = b;
        SB[i] = SB[i-1] + B[i];
    }
    mint ans = 0;
    vector<unordered_set<ll>> C(n+1);
    for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j*j<=i;j++) {
            if(i%j==0) {
                if(i/j == j) C[i].insert(j);
                else {
                    C[i].insert(j);
                    C[i].insert(i/j);
                }
            }
        }
    }
    vector<mint> D(n+1);
    for(ll i = 1;i<=n;i++) {
         D[i] = D[i-1];
         for(auto &p : C[i]) {
           if(p<=m) D[i] -=p*B[p];
         }
         D[i] +=SB[m];
         ans+=D[i]*A[i];
    }

    cout << ans.val() << "\n";
    return 0;
}