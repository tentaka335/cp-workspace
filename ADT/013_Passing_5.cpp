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
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n+1);
    vector<ll> fromone(n+1,inf);
    vector<ll> fromn(n+1,inf);
    rep(i,m) {
        ll a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q;//q.firstはq.secondまでの距離とする

    fromone[1] = 0;
    Q.push({0,1});
    while(!Q.empty()) {
        auto [cost,pos] = Q.top();
        Q.pop();
        for(ll i = 0;i<G[pos].size();i++) {
            auto [nexpos,nexcost] = G[pos][i];
            if(fromone[nexpos]>nexcost+cost) {
                fromone[nexpos] = nexcost + cost;
                Q.push({fromone[nexpos],nexpos});
            }
        }
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q1;//q.firstはq.secondまでの距離とする

    fromn[n] = 0;
    Q1.push({0,n});
    while(!Q1.empty()) {
        auto [cost,pos] = Q1.top();
        Q1.pop();
        for(ll i = 0;i<G[pos].size();i++) {
            auto [nexpos,nexcost] = G[pos][i];
            if(fromn[nexpos]>nexcost+cost) {
                fromn[nexpos] = nexcost + cost;
                Q1.push({fromn[nexpos],nexpos});
            }
        }
    }
    for(ll i = 1;i<=n;i++) cout << fromone[i] + fromn[i] << "\n";
    return 0;
}