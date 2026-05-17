#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
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
    vector<ll> a(n),b(n);
    set<Pll> xy;
    unordered_map<ll,vector<ll>> X,Y;
    rep(i,n) {
        ll x,y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
        X[x].push_back(y);
        Y[y].push_back(x);
        xy.insert({x,y});
        
    }
    for(auto &p : X) sort(all(p.second));
    for(auto &p : Y) sort(all(p.second));

    ll ans = 0;
    rep(i,n) {
        ll lx = a[i],ly = b[i];
        ll xi = lower_bound(all(Y[ly]),lx) - Y[ly].begin();
        ll yi = lower_bound(all(X[lx]),ly) - X[lx].begin();
        
        for(ll j = xi+1;j<Y[ly].size();j++) {
            for(ll k = yi + 1;k <X[lx].size();k++) {
                ll rx = Y[ly][j];
                ll ry = X[lx][k];
                if(xy.count({rx,ry})) ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}