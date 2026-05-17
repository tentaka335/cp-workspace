#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll n,m;
vector<pair<ll,ll>> ans(200009,{inf,inf});
vector<bool> visited(200009);

vector<vector<tuple<ll,ll,ll>>> G(200009);

void dfs(ll pos) {
    visited[pos] = true;
    rep(i,G[pos].size()) {
       ll nex = get<0>(G[pos][i]);
       ll nexx = get<1>(G[pos][i]);
       ll nexy = get<2>(G[pos][i]);
       if(visited[nex] == false) {
        ans[nex].first = ans[pos].first + nexx;
        ans[nex].second = ans[pos].second + nexy;
        dfs(nex);
       }

    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    rep(i,m) {
        ll a,b,x,y;
        cin >> a >> b >> x >> y;
        G[a].push_back({b,x,y});
        G[b].push_back({a,-x,-y});
    }
    ans[1] = {0,0};
    dfs(1);

    for(ll i = 1;i<=n;i++) {
        if(visited[i] == false) {
            cout << "undecidable"<< "\n";
        }
        else {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    
    
    return 0;
}