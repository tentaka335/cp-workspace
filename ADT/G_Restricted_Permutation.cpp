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

    vector<ll> ans;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> G(n+1);
    vector<ll> innum(n+1);
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        innum[b]++;
    }
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    for(ll i = 1;i<=n;i++) {
        if(innum[i]==0) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        ll pos = Q.top();
        Q.pop();
        ans.push_back(pos);
        rep(i,G[pos].size()) {
            ll nex = G[pos][i];
            innum[nex]--;
            if(innum[nex]==0) {
                Q.push(nex);
            }
        }
        G[pos].clear();
    }
    if(ans.size()!=n) {
        cout << -1;
        return 0;
    }
    else {
        rep(i,n) cout << ans[i] << " ";
    }
    
    
    return 0;
}