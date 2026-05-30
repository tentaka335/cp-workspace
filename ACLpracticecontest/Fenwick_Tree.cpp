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
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q;
    cin >> n >> q;
    fenwick_tree<ll> ft(1000000);
    
    rep(i,n) {
        ll a;
        cin >> a;
        ft.add(i,a);
    }
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==0) {
            ll p,x;
            cin >> p >> x;
            ft.add(p,x);

        } else {
            ll l,r;
            cin >> l >> r;
            cout << ft.sum(l,r) << "\n";
        }
    }
    
    return 0;
}