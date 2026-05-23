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
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> ice(n);
    rep(i,n) {
        ll f,s;
        cin >> f >> s;
        f--;
        ice[f].push_back(s);
    }
    rep(i,n) sort(ice[i].rbegin(),ice[i].rend());
    ll ans  = 0;
    vector<ll> maxice;
    rep(i,n) {
        if(ice[i].size()>=2) {
            chmax(ans,(ice[i][0]+ice[i][1]/2));
        }
        if(ice[i].size()>=1)maxice.push_back(ice[i][0]);
    }
    sort(maxice.rbegin(),maxice.rend());
    if(maxice.size()>=2) chmax(ans,maxice[0]+maxice[1]);

    cout << ans << "\n";
    
    return 0;
}