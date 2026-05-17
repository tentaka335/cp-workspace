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
    
    ll n,q;
    cin >> n >> q;
    map<Pll,pair<Pll,string>> A;//map[i][j]
    
    rep(i,n+1) {
        A[{i,0}] = {{0,0},""};
    }
    vector<ll> latest(n+1);
    
    for(ll i = 1;i<=q;i++) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll p;
            cin >> p;
            A[{p,i}] = {{0,latest[0]},""};
            latest[p] = i;
        }
        else if(qt==2) {
            ll p;
            cin >> p;
            string s;
            cin >> s;
            A[{p,i}] = {{p,latest[p]},s};
            latest[p] = i;
        } else {
            ll p;
            cin >> p;
            A[{0,i}] = {{p,latest[p]},""};
            latest[0] = i;
        }
    }

    vector<string> ans;
    ll v = latest[0];
    ll nowpc = 0;
    while(v>=1) {
       auto p = A[{nowpc,v}];
       nowpc = p.first.first;
       v = p.first.second;
       string s = p.second;
       if(s!="") ans.push_back(s);

    }

    reverse(all(ans));
    
    rep(i,ans.size()) cout << ans[i];
    cout << "\n";
    return 0;
}