#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll combi(ll a) {
    return  a*(a-1)/2;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;

    vector<ll> R(n),L(n);
    rep(i,n) cin >> L[i] >> R[i];

    ll lmax = *max_element(all(L));
    ll rmin = *min_element(all(R));

    ll lb = lmax + 1;
    ll rb = rmin - 1;
    
    ll lset;
    if(m - rb>=0) lset = combi(m-lb+1+1);
    else lset = 0;
    ll rset;
    if(rmin - 1 - 1>=0) rset = combi(rb+1);  
    else rset = 0;

    ll lrset;
    if(rmin - 1 - (lmax + 1)>=0) lrset = combi(rb - lb + 1 + 1);
    else lrset = 0;

    ll ans = lset + rset - lrset;
    cout << ans;

    return 0;



}