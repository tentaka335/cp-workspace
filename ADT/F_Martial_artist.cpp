#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

vector<vector<ll>> G(200009);
vector<bool> visited(200009);

void dfs(ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex] == false) {
            dfs(nex);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> T(n+1);

    rep(i,n) {
        cin >> T[i+1];
        ll k;
        cin >> k;
        for(ll j = 0;j<k;j++) {
            ll a;
            cin >> a;
            G[i+1].push_back(a);
        }

    }

        dfs(n);
        ll ans = 0;
        for(ll i =1;i<=n;i++) {
            if(visited[i]==true) {
                ans += T[i];
            }
        }
        cout << ans;
    
    return 0;
}