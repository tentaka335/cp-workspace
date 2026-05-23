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
ll n,m;
vector<set<ll>> G(10);


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<ll> per(n);

    for(ll i = 0;i<n;i++) per[i] = i+1;

    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }


    ll ans = inf;
    
    do {
        auto g = G;
        ll cnt = 0;
        for(ll i = 0;i<n;i++) {
            if(i==0) {
                for(ll j = 1;j<=n;j++) {
                    if(j!=per[i+1]&&j!=per[n-1]) {
                        if(g[per[i]].count(j)) {
                            g[per[i]].erase(j);
                            g[j].erase(per[i]);
                            cnt++;
                        }
                    }
                    else {
                        if(!g[per[i]].count(j)) {
                            g[per[i]].insert(j);
                            g[j].insert(per[i]);
                            cnt++;
                        }
                    }
                    
                }
            }
            else if(i==n-1) {
                  for(ll j = 1;j<=n;j++) {
                    if(j!=per[0]&&j!=per[n-2]) {
                        if(g[per[i]].count(j)) {

                           g[per[i]].erase(j);
                           g[j].erase(per[i]);
                            cnt++;
                        }
                    }
                    else {
                        if(!g[per[i]].count(j)) {
                            g[per[i]].insert(j);
                            g[j].insert(per[i]);
                            cnt++;
                        }
                    }

                }
            }
            else {
                 for(ll j = 1;j<=n;j++) {
                    if(j!=per[i-1]&&j!=per[i+1]) {
                        if(g[per[i]].count(j)) {

                           g[per[i]].erase(j);
                           g[j].erase(per[i]);
                            cnt++;
                        }
                    
                    }
                     else {
                        if(!g[per[i]].count(j)) {
                            g[per[i]].insert(j);
                            g[j].insert(per[i]);
                            cnt++;
                        }

                }
            }
            
        }
    }
        chmin(ans,cnt);
    } while(next_permutation(all(per)));
    if(n>=6) {
        
    }
    
    cout << ans << "\n";
    
    return 0;
}