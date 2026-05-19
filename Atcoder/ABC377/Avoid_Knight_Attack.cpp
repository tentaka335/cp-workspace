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
ll dx[8] = {2,2,1,1,-1,-1,-2,-2};
ll dy[8] = {1,-1,2,-2,2,-2,1,-1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    
    set<Pll> A;
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        A.insert({a,b});
         rep(v,8) {
                ll nx = a + dx[v];
                ll ny = b + dy[v];
                if(1<=nx&&nx<=n&&1<=ny&&ny<=n) {
                    A.insert({nx,ny});
                }
            }
      
    }
    ll ans = n*n - A.size();
   
    cout << ans << "\n";
    
    return 0;
}