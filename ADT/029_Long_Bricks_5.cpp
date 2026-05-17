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


using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll w,n;
    cin >> w >> n ;

    vector<S> v(w+1);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    rep(i,n) {
        ll l,r;
        cin >> l >> r;
       ll k = seg.prod(l,r+1);
       cout << k + 1 << "\n";
       seg.apply(l,r+1,k+1);
    }
    
    return 0;
}