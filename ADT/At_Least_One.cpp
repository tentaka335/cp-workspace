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
    
    ll n,m;
    cin >> n >> m;
    vector<ll> ans(m+2,0);
    vector<ll> atomaxb(m+1);
    ll maxa = 0,minb = inf;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        chmax(maxa,a);
        chmin(minb,b);
        chmax(atomaxb[a],b);
    }
    ll l = 1,r = maxa;
    ans[maxa]++;
    
    while(l<minb) {
        l++;
        chmax(r,atomaxb[l-1]);
        ans[r - l + 1]++;
        ans[m - l + 2]--;
    }

    for(ll i = 1;i<=m;i++) {
        ans[i] +=ans[i-1];
    }

    for(ll i = 1;i<=m;i++) cout << ans[i] << " ";
    
    return 0;
}