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
ll n;
Graph G(100009);
vector<bool> visited(100009);
vector<ll> famisum(100009);
ll ans = 0;

ll dfs(ll pos) {
    visited[pos] = true;
    ll res = 1;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex]==false) {
            res +=dfs(nex);
        }
    }
    if(pos!=1) {
        ans+=(n - res)*res;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i,n-1) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1);

    cout << ans << "\n";
    
    return 0;
}