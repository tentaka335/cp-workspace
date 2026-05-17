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


ll e() {
    return -inf;
}

ll op (ll a,ll b) {
    return max(a,b);
};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll w,n;
    cin >> w >> n;
    vector<segtree<ll,op,e>> DP(n+1,segtree<ll,op,e>(w+1));
   vector<ll> L(n+1),R(n+1),V(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> L[i] >> R[i] >> V[i];
    }
    for(ll i = 1;i<=n;i++) {
        DP[i].set(0,0);
    }
    for(ll i = 1;i<=n;i++) {
          if(i==1) {
                for(ll k = L[i];k<=R[i];k++)
                    DP[i].set(k,V[i]);
            }
         else for(ll j = 1;j<=w;j++) {
            if(j - L[i]<0) DP[i].set(j,DP[i-1].get(j));
            else if(j - L[i]>=0&&j - R[i] < 0) {
                ll maxv = DP[i-1].prod(0,j-L[i]+1) + V[i];
                 maxv = max(maxv,DP[i-1].get(j));
                DP[i].set(j,maxv);
            }
            else if(j-L[i]>=0&&j - R[i]>=0) {
                ll maxv = DP[i-1].prod(j - R[i],j - L[i] + 1) + V[i];
                maxv = max(maxv,DP[i-1].get(j));
                DP[i].set(j,maxv);
            }
        }
    }
    ll ans = DP[n].get(w);
    if(ans <= 0) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;


}