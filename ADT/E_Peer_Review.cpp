#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll combi3 (ll x) {
    if(x<=2) return 0;
    else return x*(x-1)*(x-2)/6;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n>> m;
    
    vector<set<ll>> ban(n+1);
    for(ll i = 0;i<m;i++) {
        ll a ,b;
        cin >> a >> b;
        ban[a].insert(b);
        ban[b].insert(a);

    }
    for(ll i = 1;i<=n;i++) {
        cout << combi3(n-1-ban[i].size()) << " ";
    }
    
    return 0;
}