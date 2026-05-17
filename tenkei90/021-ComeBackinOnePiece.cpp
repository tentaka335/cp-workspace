#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;

ll n,m;
graph G;
graph revG;
vector<bool> visited;
vector<bool> revvisited;
stack<ll> S;
ll ans = 0;
void dfs (ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex]==false) {
            dfs(nex);
        }
    }
    S.push(pos);
}

ll revdfs (ll pos) {
    revvisited[pos] = true;
    ll size = 1;
    for(ll i = 0;i<revG[pos].size();i++) {
        ll nex = revG[pos][i];
        if(revvisited[nex] == false) {
            size += revdfs(nex);
        }
    }
    return size;
}



int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    G.assign(n+1, {});
    revG.assign(n+1, {});
    visited.assign(n+1, false);
    revvisited.assign(n+1, false);
    for(ll i = 0;i<m;i++) {
        ll u,v;
        cin >> u >> v;
        G[u].push_back(v);
        revG[v].push_back(u);
    }

    for (ll v = 1; v <= n; v++) {
        if (!visited[v]) dfs(v);
    }
    
    while(!S.empty()) {
       ll pos = S.top();
       S.pop();
       if(revvisited[pos]==false) {
        ll sz = revdfs(pos);
        ans += sz*(sz-1)/2;
       }
    }
    cout << ans << "\n";
}
/*もし行き来できるグループごとにまとめることができれば、各グループごとにnC2を計算し足し合わせることで答えが出る。
このように分解することをSCC分解という。これは2回の特殊なDFSを用いて実装できる
適当な頂点から、DFSし行き止まりについたら、ついた順に番号を１，２，３..とつける。（もし行き止まりについたら、戻る）
すべての頂点を探索しきったら、今度はグラフに行き止まりについた逆順（最後から）でDFSをはじめ、行き止まりについたら、そこまでに通った点が一つの強い連結グループとなる

*/
