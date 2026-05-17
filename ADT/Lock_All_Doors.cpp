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
    
    ll n,r;
    cin >> n >> r;
    vector<ll> L(n);
   rep(i,n) cin >> L[i];

    ll ans = 0;
    bool f0 = false;

    for(ll i = 0;i<r;i++) {
        if(L[i]==0) {

            f0 = true;
            ans++;
            }
        else {
            if(f0==true) ans+=2;
        }
}
reverse(all(L));
r = n - r;

f0 = false;

    for(ll i = 0;i<r;i++) {
        if(L[i]==0) {

            f0 = true;
            ans++;
            }
        else {
            if(f0==true) ans+=2;
        }
}

cout << ans;
    
    return 0;
}