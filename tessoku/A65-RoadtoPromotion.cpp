#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
ll n;
vector<vector<ll>> G(100009);

vector<ll> DP(100009);
void treeDP (ll pos) {
    if (G[pos].size() == 0) DP[pos] = 0;
    for(ll i = 0;i<G[pos].size();i++) {
       treeDP(G[pos][i]); 
       DP[pos] +=DP[G[pos][i]] + 1;
    }
}
int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(ll i =2;i<=n;i++) {
        ll a;
        cin >> a;
        G[a].push_back(i);
    }
    treeDP(1);
    for(ll i = 1;i<=n;i++) cout << DP[i] << " ";
}
*/
