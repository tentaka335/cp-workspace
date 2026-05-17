#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;

graph G(100009);
vector<bool> visited(100009,false);
vector<bool> iswhite(100009,false);
vector<ll> white;
vector<ll> black;

void dfs (ll pos) {
    visited[pos] = true;
    for(ll i = 0;i<G[pos].size();i++) {
        ll nex = G[pos][i];
        if(visited[nex] == false) {
            iswhite[nex] = (!iswhite[pos]);
            if(iswhite[nex]) white.push_back(nex);
            else black.push_back(nex);
        dfs(nex);
        }
    }
    return ;
}


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 0;i<n-1;i++) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    iswhite[1] = true;
    white.push_back(1);
    dfs(1);
    if(white.size()>=n/2) {
        for(ll i = 0;i<n/2;i++) cout << white[i] << " ";
    }
    else for(ll i = 0;i<n/2;i++) cout << black[i] << " ";
}

/*木が二部グラフ、つまり隣接する任意の点同士を異なる色で塗ることができることを利用する。
白、黒で塗る場合、白色で塗られた点の数と黒色で塗られた点の数の内どちらかはn/2以上であ
るから、dfsで1から順に色を塗り、(posの反対の色をnexに塗る) 白黒のうち多い方をn/2個出力する。*/
