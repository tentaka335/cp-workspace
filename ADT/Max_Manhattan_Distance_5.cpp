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
    
    ll n,q;
    
    cin >> n >> q;
    vector<ll> X(n),Y(n);
    
    ll maxx = -inf,minx = inf,maxy = -inf,miny = inf;

    rep(i,n) {
        ll x,y;
        cin >> x >> y;
        X[i] = x+y;
        Y[i] = x-y;
        chmax(maxx,X[i]);
        chmax(maxy,Y[i]);
        chmin(minx,X[i]);
        chmin(miny,Y[i]);
    }
    rep(qi,q) {
        ll q;
        cin >> q;
        q--;
        ll ans = 0;
        
        chmax(ans,llabs(X[q]-minx));
        chmax(ans,llabs(X[q]-maxx));
        chmax(ans,llabs(Y[q]-miny));
        chmax(ans,llabs(Y[q]-maxy));
        cout << ans << "\n";
        
    }
    
    return 0;
}