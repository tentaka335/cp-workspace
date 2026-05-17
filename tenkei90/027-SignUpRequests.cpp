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
    set<string> regis;
    for(ll i = 0;i<n;i++) {
        string s;
        cin >> s;
        if(!regis.count(s)) {
            regis.insert(s);
            cout << i+1 << "\n";
        }
    }
}

/*setを利用し、setに名前がないなら追加しその日付を出力。あるなら何もしない*/
