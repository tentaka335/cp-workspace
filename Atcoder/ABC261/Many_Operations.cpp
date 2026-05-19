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
    
    ll n,c;
    cin >> n >> c;

    vector<ll> op(n+1),A(n+1);
    rep(i,n) {
        cin >> op[i+1] >> A[i+1];
    }
    
    vector<vector<vector<ll>>> f(2,vector<vector<ll>>(30,vector<ll>(n+1)));

    for(ll i = 0;i<30;i++) {
        f[1][i][0] = 1;
        f[0][i][0] = 0;
    }
    for(ll i = 0;i<30;i++) {//ibit目の合成関数をすべて求める。
        for(ll j = 1;j<=n;j++) {//j回合成した関数を求める。
            if(op[j]==1) {//and
                if((A[j]>>i) & 1) {
                    f[1][i][j] = 1 & f[1][i][j-1];
                    f[0][i][j] = 1 & f[0][i][j-1];
                }
                else {
                    f[1][i][j] = 0 & f[1][i][j-1];
                    f[0][i][j] = 0 & f[0][i][j-1];
                }
             
            }
            else if(op[j]==2) {

                 if((A[j]>>i) & 1) {
                    f[1][i][j] = 1 | f[1][i][j-1];
                    f[0][i][j] = 1 | f[0][i][j-1];
                }
                else {
                    f[1][i][j] = 0 | f[1][i][j-1];
                    f[0][i][j] = 0 | f[0][i][j-1];
                }


            }
            else {

                if((A[j]>>i) & 1) {
                    f[1][i][j] = 1 ^ f[1][i][j-1];
                    f[0][i][j] = 1 ^ f[0][i][j-1];
                }
                else {
                    f[1][i][j] = 0 ^ f[1][i][j-1];
                    f[0][i][j] = 0 ^ f[0][i][j-1];
                }

            }
        }
    }
    vector<ll> ans(n+1);
    ans[0] = c;
    for(ll i = 1;i<=n;i++) {
        for(ll j = 0;j<30;j++) {
            ll bit = ((ans[i-1] >> j) & (ll)1);
            ll res = f[bit][j][i];
           if(res==1) ans[i] +=((ll)1<<j);
        }
    }

    for(ll i = 1;i<=n;i++) cout << ans[i] << "\n";

    vector<vector<ll>> g(2,vector<ll>(n+1));
    g[0][0] = 0,g[1][0] = ~0;
    for(ll i = 1;i<=n;i++) {
        if(op[i]==1) {
            g[1][i] = A[i]&g[1][i-1];
            g[0][i] = A[i]&g[0][i-1];
        }
        else if(op[i]==2) {
            g[1][i] = A[i]|g[1][i-1];
            g[0][i] = A[i]|g[0][i-1];

        } else {
            g[1][i] = A[i]^g[1][i-1];
            g[0][i] = A[i]^g[0][i-1];
        }
    }
    vector<ll> ans2(n+1);
    ans2[0] = c;
    for(ll i = 1;i<=n;i++) {
        ans[i] = (ans[i-1]&g[1][i])|(~ans[i-1]&g[0][i]);
        //       1が立っているところだけ　0が立っているところだけ、
    }

    for(ll i= 1;i<=n;i++) cout << ans[i] << "\n";

    return 0;
}