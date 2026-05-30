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
ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >> w;
    vector<string> S(h);
    rep(i,h) cin >> S[i];
    vector<vector<Pll>> G(1000009);
    rep(i,h) rep(j,w) {
        ll pos = w*i+j;
        rep(v,4) {
            ll nx = i+dx[v];
            ll ny = j + dy[v];
            ll next = w*nx+ny;
            if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                if(S[nx][ny]=='.') {
                    G[pos].push_back({next,0});
                } else {
                    G[pos].push_back({next,1});
                }
                
            }
        }
         rep(v,4) {
            ll nx = i+2*dx[v];
            ll ny = j + 2*dy[v];
            ll next = w*nx+ny;
            if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                if(S[nx][ny]=='.'&&S[nx-dx[v]][ny-dy[v]]=='.') {
                    G[pos].push_back({next,0});
                } else {
                    G[pos].push_back({next,1});
                }
                
            }
        }
    
    }
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    a--;b--;c--;d--;
    
    priority_queue<Pll,vector<Pll>,greater<Pll>> Q;
    vector<ll> dist(1000009,inf);
    Q.push({0,w*a+b});
    while(!Q.empty()) {
        auto [distance,pos] = Q.top();
        Q.pop();
        if(distance>dist[pos]) continue;

        for(ll i = 0;i<G[pos].size();i++) {
            auto [next,cost] = G[pos][i];
            if(distance+cost <dist[next]) {
                dist[next] = distance + cost;
                Q.push({dist[next],next});
            }
        }
     }

     cout << dist[w*c+d] << "\n";
    
    return 0;

    
}