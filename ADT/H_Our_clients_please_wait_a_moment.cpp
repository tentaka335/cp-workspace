#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pll = pair<ll,ll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<Pll>> G(2*n+1);
    vector<vector<ll>> D(n+1,vector<ll>(n+1));
    vector<ll> cur(2*n+1,inf);

    for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j<=n;j++) {
            cin>> D[i][j];
            ll d = D[i][j];
            G[i].push_back({j,D[i][j]*a});
            G[i].push_back({n+j,D[i][j]*b+c});
            G[n+i].push_back({n+j,D[i][j]*b+c});
            G[i].push_back({n+i,c});
        }
    }


    

    

    priority_queue<Pll,vector<Pll>,greater<Pll>> Q;
    vector<bool> visited(2*n+1);
    cur[1] = 0;
    visited[1] = true;
    
    Q.push({0,1});
    while(!Q.empty()) {
        auto [cost,pos] = Q.top();
        Q.pop();  
        if(cost>cur[pos]) continue;
        for(ll i = 0;i<G[pos].size();i++) {
            auto [nex,nexcost] = G[pos][i];
            if(cost+nexcost<cur[nex]) {
                cur[nex] = cost + nexcost;
                Q.push({cur[nex],nex});
            }
        }
    }

    cout << min(cur[n],cur[2*n]) << "\n";
    return 0;
}

/*

*/