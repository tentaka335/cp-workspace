#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q;
    cin >> n >> q;
    vector<vector<ll>> L(n+1,vector<ll>(1,0));
    
    for(ll i = 1;i<=n;i++) {
        ll l;
        cin >> l;
        for(ll j = 1;j<=l;j++) {
            ll a;
            cin >> a;
            L[i].push_back(a);
        }
    }
    
    rep(qi,q) {
        ll s,t;
        cin >> s >>t;
        cout << L[s][t] << "\n";
    }
    return 0;
}