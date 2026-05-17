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
    map<ll,set<ll>> ltor,rtol;
    map<Pll,ll> S;
    rep(i,m) {
        ll l ,r;
        cin >> l >> r;
        S[{l,r}]++;
        ltor[l].insert(r);
        rtol[r].insert(l);
    }

    ll q;
    cin >> q;
    rep(qi,q) {
        ll s,t;
        cin >> s >> t;

        if(S[{s,t}]>=2) {
            cout << "Yes";
            return 0;
        }

        if(ltor.count(s)&&rtol.count(t)) {
        auto it = ltor[s].lower_bound(t);
        if(it == ltor[s].begin()) {
            cout << "No" << "\n";
            continue;
        }
        auto it2 = rtol[t].lower_bound(s);

        if(*it2<=*it) {
            cout  << "Yes" << "\n";
            continue;
        }
        
        }
        else {
            cout << "No" << "\n";
            continue;
        }

    }
    
    return 0;
}