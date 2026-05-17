#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 using Graph = vector<vector<int>>; // グラフ型// グフ


 vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする
    
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    Graph skillg(N+1);

    for(ll i=0; i<N; i++) {
        ll a,b;
        cin >> a >> b;
        
            skillg[a].push_back(i+1);
            skillg[b].push_back(i+1);
    }

     seen.assign(N+1,false);
     
    dfs(skillg, 0);
    ll ans = 0;
    for (ll i=1; i<=N; i++) {
        if (seen[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}