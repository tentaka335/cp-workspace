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

using mint = modint998244353;

const ll MOD = 998244353;

vector<mint> fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(k)
*/
void init_nCk(ll SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        fact_inv[i] = fact_inv[i - 1] * inv[i];
    }
}
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(k)
*/
mint nCk(ll n, ll k) {
    if(n<k) {
        return 0;
    }
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    mint ans = 1;
    for (ll i = n; i >= n - k + 1; i--) {
        ans *= i;
    }
    return ans * fact_inv[k];
}



Graph G(200009);
vector<ll> C(200009);
vector<ll> D(200009);
vector<Pll> E(200009);
vector<bool> visited(200009);

Pll dfs (ll pos) {

    visited[pos] = true;
    ll sum = C[pos];
    ll div = D[pos];
    Pll res;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex]==false) {
            Pll nexp = dfs(nex);
            sum +=nexp.first;
            div +=nexp.second;
        }
    }
    res = {sum,div};
    E[pos] = res;
    return res;

}



int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    init_nCk(3000000);

    ll n;

    cin >> n;
    mint ans = 1;
    for(ll i = 2;i<=n;i++) {
        ll p;
        cin >> p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    for(ll i = 1;i<=n;i++) {
        cin >> C[i];
    }
    for(ll i = 1;i<=n;i++) {
        cin >> D[i];
    }
    
    Pll k = dfs(1);

    for(ll i = 1;i<=n;i++) {
        auto [c,d] = E[i];
        ans *= nCk(c-d+D[i],D[i]);
    }

    cout << ans.val() << "\n";
    
    
    
    
    return 0;
}