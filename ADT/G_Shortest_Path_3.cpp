#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >>m;
    vector<ll> A(n+1);
    vector<bool> kaku(n+1);
    vector<ll> crr(n+1,inf);
    for(ll i = 1;i<=n;i++) cin >> A[i];

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q;


    vector<vector<pair<ll,ll>>> G(n+1);
    rep(i,m) {
        ll u,v,c;
        cin >> u >> v >> c;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    crr[1] = A[1];
    Q.push({crr[1],1}); 
    while(!Q.empty()) {
        ll pos = Q.top().second;Q.pop();
        if(kaku[pos] == true) continue;
        kaku[pos] = true;
        rep(i,G[pos].size()) {
            ll nex = G[pos][i].first;
            ll cost = G[pos][i].second;
            if(crr[nex]>crr[pos] + cost + A[nex]) {
                crr[nex] = crr[pos] + cost + A[nex];
                Q.push({crr[nex],nex});
            }

        }
    }
    for(ll i = 2;i<=n;i++) cout << crr[i] << " ";
    return 0;
}