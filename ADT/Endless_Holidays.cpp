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



bool dfs(vector<vector<ll>> &G, int v, vector<bool> &seen,  vector<bool> &finished) {
    seen[v] = true;    // 行きがけ時に true になる
    for(ll i = 0;i<G[v].size();i++) {
        ll v2 = G[v][i];

        // 頂点 v2 がすでに探索済みの場合はスキップ 
        if (finished[v2]) continue;

        // サイクル検出
        if (seen[v2] && !finished[v2]) return true;

        // 頂点 v2 を再帰的に探索
        if (dfs(G, v2, seen, finished)) return true;
    }
    finished[v] = true;  // 帰りがけ時に true になる
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
    rep(ti,t) {
        ll n,m;
        cin >> n >> m;
        bool ok = false;
        vector<ll> U(m),V(m);
        rep(i,m) {
            cin >> U[i] >>V[i];
        }
        ll w;
        cin >> w;
        vector<string> S(n+1);
        Graph G(w*n+1);
        vector<bool> visited(w*n+1),finished(w*n+1);
        for(ll i = 1;i<=n;i++) cin >> S[i];
        rep(k,m) {//曜日頂点処理
            ll u = U[k],v = V[k];
           for(ll i = 1;i<=w;i++) {
            if(i<w) {
            if(S[u][i-1]=='o'&&S[v][i]=='o') {
                G[n*(i-1)+u].push_back(n*i+v);
            }
            if(S[v][i-1]=='o'&&S[u][i]=='o') {
                G[n*(i-1)+v].push_back(n*i+u);
            }
            }
            else {
                if(S[u][w-1]=='o'&&S[v][0]=='o') {
                    G[n*(w-1)+u].push_back(v);
                }
                 if(S[v][w-1]=='o'&&S[u][0]=='o') {
                    G[n*(w-1)+v].push_back(u);
                }
            }
           }   
        }
        for(ll i = 1;i<=n;i++) {
            for(ll j = 0;j<w;j++) {
                if(S[i][j]=='o'&&S[i][(j+1)%w]=='o') {
                    G[n*(j)+i].push_back(n*((j+1)%w)+i);
                }
            }
        }

        for(ll i = 1;i<=w*n;i++) {
            if(visited[i]==false) {
                bool cycle = dfs(G,i,visited,finished);
                if(cycle) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok?"Yes":"No") << "\n";











    }
    
    return 0;
}