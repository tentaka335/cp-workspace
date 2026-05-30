#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;


ll f (ll a, ll b) {return min(a,b);};

template <typename T> struct SegmentTree {
    using F = function<T(T, T)>;
    F op;
    T e;
    ll n;
    vector<T> data;

    SegmentTree(ll N, F op, T e) : op(op), e(e) {
        n = 1;
        while (n < N) n *= 2;
        data.assign(2 * n, e);
    }

    void set(int i, T val) {
        i += n;
        data[i] = val;
        while (i > 1) {
            i >>= 1;
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }

    T query(int l, int r) {
        T resL = e, resR = e;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = op(resL, data[l++]);
            if (r & 1) resR = op(data[--r], resR);
        }
        return op(resL, resR);
    }
};


ll infinity() {
    return inf;
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q;
    cin >> n >> q;
   
    SegmentTree<ll> seg(n,f,inf);
    rep(i,n) {
        ll a;
        cin >> a;
        seg.set(i,a);
    }

    rep(qi,q) {
        ll l,r;
        cin >> l >> r;
        cout << seg.query(l,r) << "\n";
    }
    
    return 0;
}